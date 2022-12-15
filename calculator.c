
#include "application.h"

int main() {
   Std_ReturnType ret = E_NOT_OK;
    
   chr_lcd_8bit_t lcd_user = {
      .lcd_en.direction = GPIO_DIRECTION_OUTPUT ,
      .lcd_en.logic = GPIO_LOW , 
      .lcd_en.port = PORTB_INDEX , 
      .lcd_en.pin = GPIO_PIN0,
      
      .lcd_rs.direction = GPIO_DIRECTION_OUTPUT , 
      .lcd_rs.logic = GPIO_LOW , 
      .lcd_rs.port = PORTB_INDEX , 
      .lcd_rs.pin = GPIO_PIN1,
      
      .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT , .lcd_data[0].logic = GPIO_LOW , .lcd_data[0].port = PORTA_INDEX , .lcd_data[0].pin = GPIO_PIN0,
      .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT , .lcd_data[1].logic = GPIO_LOW , .lcd_data[1].port = PORTA_INDEX , .lcd_data[1].pin = GPIO_PIN1,
      .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT , .lcd_data[2].logic = GPIO_LOW , .lcd_data[2].port = PORTA_INDEX , .lcd_data[2].pin = GPIO_PIN2,
      .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT , .lcd_data[3].logic = GPIO_LOW , .lcd_data[3].port = PORTA_INDEX , .lcd_data[3].pin = GPIO_PIN3,
      .lcd_data[4].direction = GPIO_DIRECTION_OUTPUT , .lcd_data[4].logic = GPIO_LOW , .lcd_data[4].port = PORTC_INDEX , .lcd_data[4].pin = GPIO_PIN7,
      .lcd_data[5].direction = GPIO_DIRECTION_OUTPUT , .lcd_data[5].logic = GPIO_LOW , .lcd_data[5].port = PORTA_INDEX , .lcd_data[5].pin = GPIO_PIN5,
      .lcd_data[6].direction = GPIO_DIRECTION_OUTPUT , .lcd_data[6].logic = GPIO_LOW , .lcd_data[6].port = PORTB_INDEX , .lcd_data[6].pin = GPIO_PIN2,
      .lcd_data[7].direction = GPIO_DIRECTION_OUTPUT , .lcd_data[7].logic = GPIO_LOW , .lcd_data[7].port = PORTB_INDEX , .lcd_data[7].pin = GPIO_PIN3,
    };
    keypad_t keypad_user = {
    .keypad_row_pins[0].direction=GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[0].logic=GPIO_LOW,
    .keypad_row_pins[0].port=PORTD_INDEX,
    .keypad_row_pins[0].pin = GPIO_PIN0,
    .keypad_row_pins[1].direction=GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[1].logic=GPIO_LOW,
    .keypad_row_pins[1].port=PORTD_INDEX,
    .keypad_row_pins[1].pin = GPIO_PIN1,
    .keypad_row_pins[2].direction=GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[2].logic=GPIO_LOW,
    .keypad_row_pins[2].port=PORTD_INDEX,
    .keypad_row_pins[2].pin = GPIO_PIN2,
    .keypad_row_pins[3].direction=GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[3].logic=GPIO_LOW,
    .keypad_row_pins[3].port=PORTD_INDEX,
    .keypad_row_pins[3].pin = GPIO_PIN3,

    .keypad_col_pins[0].direction = GPIO_DIRECTION_INPUT,
    .keypad_col_pins[0].logic=GPIO_LOW,
    .keypad_col_pins[0].port=PORTD_INDEX,
    .keypad_col_pins[0].pin = GPIO_PIN4,
    .keypad_col_pins[1].direction = GPIO_DIRECTION_INPUT,
    .keypad_col_pins[1].logic=GPIO_LOW,
    .keypad_col_pins[1].port=PORTD_INDEX,
    .keypad_col_pins[1].pin = GPIO_PIN5,
    .keypad_col_pins[2].direction = GPIO_DIRECTION_INPUT,
    .keypad_col_pins[2].logic=GPIO_LOW,
    .keypad_col_pins[2].port=PORTD_INDEX,
    .keypad_col_pins[2].pin = GPIO_PIN6,
    .keypad_col_pins[3].direction = GPIO_DIRECTION_INPUT,
    .keypad_col_pins[3].logic=GPIO_LOW,
    .keypad_col_pins[3].port=PORTD_INDEX,
    .keypad_col_pins[3].pin = GPIO_PIN7,
    };
    label: 
    lcd_8bit_initialize(&lcd_user);//initializes the LCD screen
    keypad_initialize(&keypad_user);//initializes the keypad
    
	uint8 arr[6]={KEY_RELEASED,KEY_RELEASED,KEY_RELEASED,KEY_RELEASED,KEY_RELEASED,KEY_RELEASED};
    uint16 res;
    uint8 counter=0;
	
   while(1){
       //sending and checking 1st char (num1 1st digit)
       do{  
           ret = keypad_get_value(&keypad_user , &arr[counter]);	
        }while(arr[counter]==KEY_RELEASED);
        if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/'){
            ret = lcd_8bit_send_command(&lcd_user , LCD_CLEAR );
            goto label ;
        }
        else
        {
            ret = lcd_8bit_send_char_data(&lcd_user , arr[counter] );
        }
        counter++;
        __delay_ms(300);
        //sending and checking 2nd char (num1 2nd digit)
        do{  
           ret = keypad_get_value(&keypad_user , &arr[counter]);	
        }while(arr[counter]==KEY_RELEASED);
        if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/'){
            ret = lcd_8bit_send_command(&lcd_user , LCD_CLEAR );
            goto label ;
        }
        else
        {
            ret = lcd_8bit_send_char_data(&lcd_user , arr[counter] );
        }
        counter++;
        __delay_ms(300);
        //sending and checking 3rd char (operator)
        do{  
           ret = keypad_get_value(&keypad_user , &arr[counter]);	
        }while(arr[counter]==KEY_RELEASED);
        if((arr[counter]=='A')||(arr[counter]=='=')){
            ret = lcd_8bit_send_command(&lcd_user , LCD_CLEAR );
            goto label ;
        }
        else
        {
            ret = lcd_8bit_send_char_data(&lcd_user , arr[counter] );
        }
        counter++;
        __delay_ms(300);
        //sending and checking 4th char (num2 1st digit)
        do{  
           ret = keypad_get_value(&keypad_user , &arr[counter]);	
        }while(arr[counter]==KEY_RELEASED);
        if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/'){
            ret = lcd_8bit_send_command(&lcd_user , LCD_CLEAR );
            goto label ;
        }
        else
        {
            ret = lcd_8bit_send_char_data(&lcd_user , arr[counter] );
        }
        counter++;
        __delay_ms(300);
        //sending and checking 5th char (num2 2nd digit)
        do{  
           ret = keypad_get_value(&keypad_user , &arr[counter]);	
        }while(arr[counter]==KEY_RELEASED);
        if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/'){
            ret = lcd_8bit_send_command(&lcd_user , LCD_CLEAR );
            goto label ;
        }
        else
        {
            ret = lcd_8bit_send_char_data(&lcd_user , arr[counter] );
        }
        counter++;
        __delay_ms(300);
        //sending and checking 6th char (=)
        do{  
           ret = keypad_get_value(&keypad_user , &arr[counter]);	
        }while(arr[counter]==KEY_RELEASED);
        if(arr[counter]=='='){
		ret = lcd_8bit_send_char_data(&lcd_user , arr[counter] );
		switch(arr[counter-3])
		{
			case '+':
			res=(arr[counter-4]-48)+((arr[counter-5]-48)*10)+((arr[counter-2]-48)*10)+(arr[counter-1]-48);
			if(res>=100&&res<1000){
				ret = lcd_8bit_send_char_data(&lcd_user , (res/100)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , ((res/10)%10)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , (res%10)+48 );
			}
			else if (res>=10&&res<100){
				ret = lcd_8bit_send_char_data(&lcd_user , (res/10)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , (res%10)+48 );
			}
			else if(res<10){
                ret = lcd_8bit_send_char_data(&lcd_user , res+48 );
			}
			break;
            
			case '-' :
			res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))-(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(res>=100&&res<1000){
				ret = lcd_8bit_send_char_data(&lcd_user , (res/100)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , ((res/10)%10)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , (res%10)+48 );
			}
			else if (res>=10&&res<100){
				ret = lcd_8bit_send_char_data(&lcd_user , (res/10)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , (res%10)+48 );
			}
			else if(res<10){
                ret = lcd_8bit_send_char_data(&lcd_user , res+48 );
			}
			break;
            
			case '*':
			res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(res>=100&&res<1000){
				ret = lcd_8bit_send_char_data(&lcd_user , (res/100)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , ((res/10)%10)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , (res%10)+48 );
			}
			else if (res>=10&&res<100){
				ret = lcd_8bit_send_char_data(&lcd_user , (res/10)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , (res%10)+48 );
			}
			else if(res<10){
                ret = lcd_8bit_send_char_data(&lcd_user , res+48 );
			}
			break;
            
			case '/':
			res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))/(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(res>=100&&res<1000){
				ret = lcd_8bit_send_char_data(&lcd_user , (res/100)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , ((res/10)%10)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , (res%10)+48 );
			}
			else if (res>=10&&res<100){
				ret = lcd_8bit_send_char_data(&lcd_user , (res/10)+48 );
				ret = lcd_8bit_send_char_data(&lcd_user , (res%10)+48 );
			}
			else if(res<10){
                ret = lcd_8bit_send_char_data(&lcd_user , res+48 );
			}
			break;
            
			default : break;
			
		}
	}
	else
	{
		ret = lcd_8bit_send_command(&lcd_user , LCD_CLEAR );
		goto label ;
	}
	__delay_ms(200);
   }

    return (EXIT_SUCCESS);
}

