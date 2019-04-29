# database-array
store a string in an array of strings if not present add the string. If present update the associated value to that string in the 
same string position no of the array.

The following two functions will log incoming data from a scanner or PORT.  
Logged data is stored locally in RAM. The function first check if the string position no in the array is empty. 
If empty it will check if the string ID or MAC is already present in the array. If the new data string received is not already in the
array it will add it with the corresponding data attached to that ID/MAC/IP address. 
If the string ID is present it will check if the data is different to  the last entry. 
If different it will update and send to the cloud. This is particularly usefull when working with mesh and GSM/LTE/NB-IOT applications 
where one only want to send data that has changed and should be updated.

As an optional extra  the array is flushed every 5 min via a timer. The purpose for this is that when one is  
reading wireless sensors you can monitor when a sensor has gone missing. i.e if you have not heard from a rf sensor 
in more than 5 min presume it missing or dead.

