# Universal_IR_remote

Universal IR remote using IRremote by Ken Shirriff's

I'm using LG air conditioner remote, any IR remote will work.  

Steps:
- Include the library file in your arduino libray folder by going to Sketch/Include Library/Add .zip Library..
- Run the check_manufacturer sketch to know the hex code of your remote and manufacturer name. In my case 0x88C0051 and LG
- To made universal ir remote, run the Send_irCode skecth, enter your hex code and change the send function depending upon your manufacturer. eg.: NEC use SendNEC, sony use SendSony...etc

HAVE FUN!!!
