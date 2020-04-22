/*
 * Morse EnCoder
 * 
 * Caleb Whitman
 * Microprocessor Systems
 * Dr. Buckhanan
 * Andrews University
 * 04/22/20
 * 
 * Program to take any alphanumeric string and translate it into Morse code, then display that Morse code with the builtin LED
 * Arduino Pro Micro using as much in-line assembly (asm) as I could.
 */

void setup(){}

void loop()
{

  //TURNS OFF BUILT IN LED
  __asm__ volatile
  (
    
    "cbi %0, %1 \n\t"
    : : "I" (_SFR_IO_ADDR(PINB)), "I" (PB0)
    
  );

  //START DELAY
  for (long i = 0; i < 16000000; i++)
  {

    //turns off the light
    __asm__ volatile
    (
      
      "nop\n"
      
    );
    
  }

  /*
   * Please note while entering your String that this program, due to my limited knowledge of how Morse code works, only
   * accepts alphanumeric values (a-z & 0-9) as well as spaces. It does not support special characters at all, please don't
   * use them, much thanks. The morse code alphabet i worked off of didn't show anything for punctuation and stuff. That
   * said, you can use capitals if you want, but since there are't capitals as such in Morse code, this program will just
   * treat all letters as though they are lower case.
   */
  String myString = "hello world";      //<<<<<<ENTER YOUR STRING HERE<<<<<<
  int strLen = myString.length();       //gets string length
  
  for(int i = 0; i < strLen; i++)       //itterates for the length of the string
  {

    char symbol = myString.charAt(i);   //
    interpret(tolower(symbol));
    
  }

  //ENDING FUNCTION
  while(1)
  {

     //turns off the light
      __asm__ volatile
    (
    
      "cbi %0, %1 \n\t"
      : : "I" (_SFR_IO_ADDR(PINB)), "I" (PB0)
    
    );
    
  };

}

/* ____________________________________________________
 * |                                                  |
 * |FUNCTIONS FOR MAKING THE NECESSARY LIGHT SEQUENCES|
 * |__________________________________________________|
 * |          |         |         |         |         |
 * |          |         |         |         |         |
 * V          V         V         V         V         V
 */

void dash()                                         //FUNCTION FOR MAKING A DASH
{
  
  __asm__ volatile
  (
    
    "sbi %0, %1 \n\t"
    : : "I" (_SFR_IO_ADDR(PINB)), "I" (PB0)
    
  );
  
  for (long i = 0; i < 1000000; i++)
  {
    
    __asm__ volatile
    (
      
      "nop\n"
      
    );
    
  }
  
  __asm__ volatile
  (
    
    "cbi %0, %1 \n\t"
    : : "I" (_SFR_IO_ADDR(PINB)), "I" (PB0)
    
  );
  
}

void space()                                        //FUNCTION FOR MAKING A SPACE
{
  
  __asm__ volatile
  (
    
    "cbi %0, %1 \n\t"
    : : "I" (_SFR_IO_ADDR(PINB)), "I" (PB0)
    
  );

  for (long i = 0; i < 4000000; i++)
  {
    
    __asm__ volatile
    (
      
      "nop\n"
      
    );
    
  }
  
}

void wait()                             //FUNCTION FOR CREATING SPACING BEWTWEEN DOTS AND DASHES
{
  
  __asm__ volatile
  (
    
    "cbi %0, %1 \n\t"
    : : "I" (_SFR_IO_ADDR(PINB)), "I" (PB0)
    
  );
  
  for (long i = 0; i < 250000; i++)
  {
    
    __asm__ volatile
    (
      
      "nop\n"
      
    );
    
  }
  
}

void endl()                                 //FUNCTION FOR CREATING SPACE BETWEEN CHARACTERS
{
  
  __asm__ volatile
  (
    
    "cbi %0, %1 \n\t"
    : : "I" (_SFR_IO_ADDR(PINB)), "I" (PB0)
    
  );
  
  for (long i = 0; i < 1000000; i++)
  {
    
    __asm__ volatile
    (
      
      "nop\n"
      
    );
    
  }
  
}

void dot()                                            //FUNCTION FOR MAKING DOTS
{
    
  __asm__ volatile
  (
    
    "sbi %0, %1 \n\t"
    : : "I" (_SFR_IO_ADDR(PINB)), "I" (PB0)
    
  );
  
  for (long i = 0; i < 250000; i++)
  {
    
    __asm__ volatile
    (
      
      "nop\n"
      
    );
    
  }
  
  __asm__ volatile
  (
    
    "cbi %0, %1 \n\t"
    : : "I" (_SFR_IO_ADDR(PINB)), "I" (PB0)
    
  );
  
}

/* ____________________________________________________
 * |                                                  |
 * |FUNCTION FOR INTERPRETING THE STRING TO MORSE CODE|
 * |__________________________________________________|
 * |          |         |         |         |         |
 * |          |         |         |         |         |
 * V          V         V         V         V         V
 */

void interpret(char symbol)
{
  
  if(symbol == 'a'){a();}
  if(symbol == 'b'){b();}
  if(symbol == 'c'){c();}
  if(symbol == 'd'){d();}
  if(symbol == 'e'){e();}
  if(symbol == 'f'){f();}
  if(symbol == 'g'){g();}
  if(symbol == 'h'){h();}
  if(symbol == 'i'){i();}
  if(symbol == 'j'){j();}
  if(symbol == 'k'){k();}
  if(symbol == 'l'){l();}
  if(symbol == 'm'){m();}
  if(symbol == 'n'){n();}
  if(symbol == 'o'){o();}
  if(symbol == 'p'){p();}
  if(symbol == 'q'){q();}
  if(symbol == 'r'){r();}
  if(symbol == 's'){s();}
  if(symbol == 't'){t();}
  if(symbol == 'u'){u();}
  if(symbol == 'v'){v();}
  if(symbol == 'w'){w();}
  if(symbol == 'x'){x();}
  if(symbol == 'y'){y();}
  if(symbol == 'z'){z();}
  if(symbol == ' '){space();}
  if(symbol == '1'){one();}
  if(symbol == '2'){two();}
  if(symbol == '3'){three();}
  if(symbol == '4'){four();}
  if(symbol == '5'){five();}
  if(symbol == '6'){six();}
  if(symbol == '7'){seven();}
  if(symbol == '8'){eight();}
  if(symbol == '9'){nine();}
  if(symbol == '0'){zero();}
  
}

/* ____________________________________________________
 * |                                                  |
 * | FUNCTIONS FOR CREATING ALPHANUMERIC MORSE LIGHTS |
 * |__________________________________________________|
 * |          |         |         |         |         |
 * |          |         |         |         |         |
 * V          V         V         V         V         V
 */

void zero()
{
  dasher();
  dasher();
  dasher();
  dasher();
  dasher();
  endl();
}

void nine()
{
  dasher();
  dasher();
  dasher();
  dasher();
  dotter();
  endl();
}

void eight()
{
  dasher();
  dasher();
  dasher();
  dotter();
  dotter();
  endl();
}

void seven()
{
  dasher();
  dasher();
  dotter();
  dotter();
  dotter();
  endl();
}

void six()
{
  dasher();
  dotter();
  dotter();
  dotter();
  dotter();
  endl();
}

void five()
{
  dotter();
  dotter();
  dotter();
  dotter();
  dotter();
  endl();
}

void four()
{
  dotter();
  dotter();
  dotter();
  dotter();
  dasher();
  endl();
}

void three()
{
  dotter();
  dotter();
  dotter();
  dasher();
  dasher();
  endl();
}

void two()
{
  dotter();
  dotter();
  dasher();
  dasher();
  dasher();
  endl();
}

void one()
{
  dotter();
  dasher();
  dasher();
  dasher();
  dasher();
  endl();
}

void z()
{
  dasher();
  dasher();
  dotter();
  dotter();
  endl();
}

void y()
{
  dasher();
  dotter();
  dasher();
  dasher();
  endl();
}

void x()
{
  dasher();
  dotter();
  dotter();
  dasher();
  endl();
}

void w()
{
  dotter();
  dasher();
  dasher();
  endl();
}

void v()
{
  dotter();
  dotter();
  dotter();
  dasher();
  endl();
}

void u()
{
  dotter();
  dotter();
  dasher();
  endl();
}

void t()
{
  dasher();
  endl();
}

void s()
{
  dotter();
  dotter();
  dotter();
  endl();
}

void r()
{
  dotter();
  dasher();
  dotter();
  endl();
}

void q()
{
  dasher();
  dasher();
  dotter();
  dasher();
  endl();
}

void p()
{
  dotter();
  dasher();
  dasher();
  dotter();
  endl();
}

void o()
{
  dasher();
  dasher();
  dasher();
  endl();
}

void n()
{
  dasher();
  dotter();
  endl();
}

void m()
{
  dasher();
  dasher();
  endl();
}

void l()
{
  dotter();
  dasher();
  dotter();
  dotter();
  endl();
}

void k()
{
  dasher();
  dotter();
  dasher();
  endl();
}

void j()
{
  dotter();
  dasher();
  dasher();
  dasher();
  endl();
}

void i()
{
  dotter();
  dotter();
  endl();
}

void h()
{
  dotter();
  dotter();
  dotter();
  dotter();
  endl();
}

void g()
{
  dasher();
  dasher();
  dotter();
  endl();
}

void f()
{
  dotter();
  dotter();
  dasher();
  dotter();
  endl();
}

void e()
{
  dotter();
  endl();
}

void d()
{
  dasher();
  dotter();
  dotter();
  endl();
}

void c()
{
  dasher();
  dotter();
  dasher();
  dotter();
  endl();
}

void b()
{
  dasher();
  dotter();
  dotter();
  dotter();
  endl();
}

void a()
{
  dotter();
  dasher();
  endl();
}

/* ____________________________________________________
 * |                                                  |
 * | COMPENSATION FUNCTIONS FOR THE WEIRD SKIP THING  |
 * |__________________________________________________|
 * |          |         |         |         |         |
 * |          |         |         |         |         |
 * V          V         V         V         V         V
 */

void dotter()
{
  dot();
  wait();
  dot();
  wait();
}

void dasher()
{
  dash();
  wait();
  dash();
  wait();
}
