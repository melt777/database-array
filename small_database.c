
uint8_t Beacon_MAC[5][7] = {NULL}; //make sure they are 0
uint8_t Beacon_Temperature[5][2] = {NULL};

int MAC_string_max = 5; // maximum amount of string held
uint8_t Beacon_MAC_store_to_compare[7] =  {NULL}; // Temporary  store the mac to compare previous entries to no \0 terminator
uint8_t Beacon_MAC_temperature_to_compare[2] = {NULL}; // Temporary  store the temperature to compare previous entries to no \0 terminator
bool MAC_already_present; // flag if string already in array
bool MAC_string_empty=false; // flag to check if string position no is empty




int scan_array_no(void) // returned the string in the array no
{ 

 // for (MAC_string_no_count;MAC_string_no_count<MAC_string_max;MAC_string_no_count++) // scan next string and increment

        
        if (*Beacon_MAC[MAC_string_no] == NULL) // if mac addres no is zero c        {
           {  MAC_string_empty=true;
             return (MAC_string_no);
           }   
              
     else if (*Beacon_MAC[MAC_string_no] != NULL) // if mac addres not is zero 
          {
          MAC_string_empty=false;
            return (MAC_string_no);
          }

}



if (true)
// we now know its  our beacon so lets start.
      {  
      memcpy(Beacon_MAC_store_to_compare,(void*)&RX_Data[18], 6); // copy only the beacon mac temporary for saving to compare
        memcpy(Beacon_MAC_temperature_to_compare,(void*)&RX_Data[14], 1); // copy only the beacon temperature for saving to compare
           
      for (MAC_string_no;MAC_string_no<MAC_string_max; MAC_string_no++ ) // scan MAC_string_max = 5 strings in the array

            {
             MAC_string_no = scan_array_no();  //  set array string no flag empty or not
               
                  if (MAC_string_empty==true)  // string is empty , add the data and exit.        

                  {
                    memcpy ( Beacon_MAC[MAC_string_no], Beacon_MAC_store_to_compare, 6); // copy  the beacon mac address 
                    memcpy ( Beacon_Temperature[MAC_string_no], Beacon_MAC_temperature_to_compare,1); // copy  the beacon mac temprature 
                    Sent_to_ESP32();// upload to wifi
                    MAC_string_no=0;//reset counter we need to check from beginning each time
                    Beacon_MAC_store_to_compare[7] = '\0'; //clear beacon_mac_temp
               
                   break;
                  }
            
              //here we know the string position  in the array is not empty.
              //if the new received  string is already in the array dont add it again. simply over write the previous string 
     
              if (!strcmp (Beacon_MAC_store_to_compare,Beacon_MAC[MAC_string_no])) //if it is the same string (mac address)
                 {
                        if (strcmp(Beacon_MAC_temperature_to_compare,Beacon_Temperature[MAC_string_no])) // temp has changed
                        {   Sent_to_ESP32();} // upload to wifi
                  memcpy(Beacon_MAC[MAC_string_no],Beacon_MAC_store_to_compare,6); // copy only the beacon mac temporary for saving to compare
                  memcpy  (Beacon_Temperature[MAC_string_no], Beacon_MAC_temperature_to_compare, 1); // copy  the beacon mac temprature 
                  Beacon_MAC_store_to_compare[7] = '\0'; //clear beacon mac temp     
                  MAC_string_no=0;//reset counter we need to check from beginning each time
                  break;
                 }

            }

      }
