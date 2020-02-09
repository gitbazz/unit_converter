/* 
* Program to perform some simple conversions 
* Author: Bazillah Zargar
*/
#include <stdio.h>
#include <stdlib.h>

/* Prompts user to select direction of conversion (km, m) */
char conversionDirection1(void){ 
    char inputChar;
    do {
        printf("Enter a character to select the direction for conversion:\r\nK for conversion from Kilometer to Mile\r\nM for conversion from Mile to Kilometer\r\n");
        scanf(" %c", &inputChar);
    } while ((inputChar != 'K') && (inputChar != 'M'));
    return inputChar; 
}

/* Prompts user to select direction of conversion (m, ft) */
char conversionDirection2(void){ 
    char inputChar;
    do {
    printf("Enter a character to select the direction for conversion:\r\nM for conversion from Meter to Feet\r\nF for conversion from Feet to Meter\r\n");
    scanf(" %c", &inputChar); 
    } while ((inputChar != 'M') && (inputChar != 'F'));
    return inputChar; 
}

/* Prompts user to select direction of conversion (cm, in) */
char conversionDirection3(void){ 
    char inputChar;
    do {
    printf("Enter a character to select the direction for conversion:\r\nC for conversion from Centimetre to Inch\r\nI for conversion from Inch to Centimetre\r\n");
    scanf(" %c", &inputChar); 
    } while ((inputChar != 'C') && (inputChar != 'I'));
    return inputChar; 
}

/* Prompts user to select direction of conversion (C, F) */
char conversionDirection4(void){ 
    char inputChar;
    do {
    printf("Enter a character to select the direction for conversion:\r\nC for conversion from Celcius to Farenheit\r\nF for conversion from Farenheit to Celcius\r\n");
    scanf(" %c", &inputChar);
    } while ((inputChar != 'C') && (inputChar != 'F')); 
    return inputChar; 
}

/* Takes units and conversion rate as input, performs calculation, and displays new converted value 
* @unitFrom is the unit of the value to be converted
* @unitTo is the unit the value is being converted to
* @conversionRate is the unit conversion rate */
int convert(char unitFrom[], char unitTo[], float conversionRate){
    float inputValue, result;
    printf("Enter the float value you wish to convert:");
    scanf("%f", &inputValue);
    result = inputValue*conversionRate;
    printf("%f %s is equal to %f %s \r\n", inputValue, unitFrom, result, unitTo);
    return 0;
}

/* Takes units as input, performs calculation, and displays new converted value in Farenheit
* @unitFrom is the unit of the value to be converted
* @unitTo is the unit the value is being converted*/
int celciusToFarenheit(char unitFrom[], char unitTo[]){
    float inputValue, result;  
    printf("Enter the float value you wish to convert:");
    scanf("%f", &inputValue);
    result = (inputValue*1.8)+32;
    printf("%f %s is equal to %f %s \r\n", inputValue, unitFrom, result, unitTo);
    return 0;
}

/* Takes units as input, performs calculation, and displays new converted value in Celcius
* @unitFrom is the unit of the value to be converted
* @unitTo is the unit the value is being converted*/
int farenheitToCelcius(char unitFrom[], char unitTo[]){
    float inputValue, result;
    printf("Enter the float value you wish to convert:");
    scanf("%f", &inputValue);
    result = (inputValue-32)/1.8;
    printf("%f %s is equal to %f %s \r\n", inputValue, unitFrom, result, unitTo);
    return 0;
}

/* Main method - prompts user to select units for conversion */
int main(void){
    
    int inputInt=0;
    char direction;
    
    /* Prompts user to enter an integer from 1-5 to select a conversion */
    while (inputInt != 5){
    do {
        printf("Enter an integer from 1-5 to select one of the following options:\r\n1 - for conversion between Kilometer and Mile\r\n2 - for conversion between Meter and Feet\r\n3 - for conversion between Centimetre and Inch\r\n4 - for conversion between Celsius and Farenheit\r\n5 - quit\r\n");
        scanf("%d", &inputInt); 
    
        /* Prompts user to select a direction for conversion and then displays the result */
        if (inputInt == 1) {
            direction = conversionDirection1();
            if (direction == 'K') {
                convert("km", "mi", 0.621371);
            } else if (direction == 'M') {
                convert("mi", "km", 1.60934);
            }
        } else if (inputInt == 2) {
            direction = conversionDirection2();
            if (direction == 'M') {
                convert("m", "ft", 3.28084);
            } else if (direction == 'F') {
                convert("ft", "m", 0.3048);
            }
        } else if (inputInt == 3) {
            direction = conversionDirection3();
            if (direction == 'C') {
                convert("cm", "in", 0.393701);
            } else if (direction == 'I') {
                convert("in", "cm", 2.54);
            }
        } else if (inputInt == 4) {
            direction = conversionDirection4();
            if (direction == 'C') {
                celciusToFarenheit("C", "F");
            } else if (direction == 'F') {
                farenheitToCelcius("F", "C");
            }
        } else if (inputInt == 5) {
            exit(0);
        }
    } while (inputInt <1 || inputInt > 5); 
    }
    return 0;
}

