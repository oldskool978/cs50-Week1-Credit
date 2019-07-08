 cs50-Week1-Credit 
Harvard cs50 Week 1, Credit Challenge. Portable (no use of cs50.h) 

# library Credit.H 
I have included a self contained library that encapsulate several functions that assist in evaluating user input.
 <br>

## void Get_NuMber(void)

Something like cs50's Get_Long.. but its not.
it does not allow for a string output like get_long does.  
Using a for loop, isdigit(), and isspace(); this function queries the user for a positive number.
Anything that isnt a solid number is rejected.
user is demanded input until a string of numbers is entered. 
The number supplied is stored in character array NuMber. 
NuMber uses malloc to allocate memory dynamically. 
NuMber is released from memory every time this function is called. 
it can be used many times over with little worry of memory allocation and overflows.

<b>
example:
 <br>
void main(void) <br>
{ <br>
  Get_NuMber();<br>
  printf ("%s", NuMber);<br>
} 

  <p align="center">
 In practice, the code in this example will continue to ask for a number so long as a valid number is not entered.
 Once a valid number is entered, the code written above will return that value as a string; using a printf statement. 
  </p>
 </b>


## LuHn(NuMber) 

Luhn's algorithm is a checksum applied to Credit Card numbers for added security. The algorithm multiplies every second number by two, starting from the end. Any sum that is greater than 10 is added together (ie. 8 * 2 = 18, so 18 would become 1 + 8). Every number that hasn't been multiplied by 2 then gets added to the sum. Once luhns algorithm is executed and a checksum is obtained, the value can then be validated. Commonly the checksum is validated by checking that the resulting value is divisible by 10. 
  
The LuHn(char*) Function accepts a Character array that is 20 digits long, That is 19 numbers and a terminator value. The function returns an int that is equivalent to the checksum amount. 
  </p>
  <b>
  example:
 <br>
void main(void) <br>
{ <br>
  Get_NuMber();<br>
  printf ("%i", LuHn(NuMber);<br>
} 
 
  <p align="center">
  The example above uses Get_NuMber to query user for a valid number. The number generated by Get_NuMbers (NuMbers) is fed to LuHn which reports back with the checksum value via printf statement. Note that the value returned is an int.  
</p>
 </b>


## char *isitValid(char* ) 

 isitValid is a character array that accepts a character array. This function acts as a gatekeeper, returning a string value reflecting the type of creditcard validated. This function is tailored to carry out the objectives set by Harvard cs50's 2019 Week 1 problem set. The function invalidates any char array with less than 12 digits, exactly 14 digits, or anything over 17 digits. Once those conditions are met, a switch loop executes using the first two digits of the credit card number as as well as luhn's algorithm; as a means to validate the card issuer.
 
   <b>
  example:
 
 <br>
void main(void) <br>
{ <br>
  Get_NuMber();<br>
  printf ("%s", isitValid(NuMber));<br>
} 
 
 </p>
 <p align="center">
  When executed, the code above is all that's necessary to fulfill every requirement set by cs50's week1 problem set. Any number too big or small to be valid is rejected. Internally the function multiplies the numeric value of pointer[0] by 10 and adds the value of pointer[1]. The result will be equivalent to the first two digits of the array.
  
 (ie. if NuMber = 3659848565867 then (((NuMber[0] -'0') * 10) + (NuMber[1] - '0')) == 36)<br>
 (ie. if NuMBer = 5326985477552 then (((NuMber[0] -'0') * 10) + (NuMber[1] - '0')) == 53)<br>
 (ie. if NuMBer = 7112682439112 then (((NuMber[0] -'0') * 10) + (NuMber[1] - '0')) == 71)<br>
 
 this function follows the switch loop with an if statement, that is; if ((LuHn(NuMber) % 10) == 0)
 In the event that the if statement is true, the card corresponding issuer is returned as a string. 
 Switch defaults to returning "INVALID\n".  INVALID is returned unless every requirement is fulfilled.  
 </p>
  </b>
 
