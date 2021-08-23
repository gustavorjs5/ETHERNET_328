
#include <EtherCard.h>
#include <Wire.h>
#include "RTClib.h"
#include <EEPROM.h>
#include <avr/wdt.h>
#include <TimerOne.h>

#define ON    1
#define OFF   0
#define IN1 A3
#define IN2 A2
#define IN3 A1
#define IN4 A0
#define OUT1 2
#define OUT2 3
#define OUT3 4
#define OUT4 5
#define OUT5 6
#define OUT6 7
#define OUT7 8
#define OUT8 9
#define CONFIRMACION 1

#define EE_IP_BYTE_1 1
#define EE_IP_BYTE_2 2
#define EE_IP_BYTE_3 3
#define EE_IP_BYTE_4 4

#define EE_SALIDAS_TEMPORIZADAS    5
#define EE_TIEMPO_TEMPORIZADA_OUT1 6 
#define EE_TIEMPO_TEMPORIZADA_OUT2 7
#define EE_TIEMPO_TEMPORIZADA_OUT3 8
#define EE_TIEMPO_TEMPORIZADA_OUT4 9
#define EE_TIEMPO_TEMPORIZADA_OUT5 10
#define EE_TIEMPO_TEMPORIZADA_OUT6 11
#define EE_TIEMPO_TEMPORIZADA_OUT7 12
#define EE_TIEMPO_TEMPORIZADA_OUT8 13
#define EE_SALIDAS_RELOJ_ON        14
#define EE_OUT1_HORA_ON            15
#define EE_OUT1_MINUTOS_ON         16
#define EE_OUT1_DIA_ON             17
#define EE_OUT2_HORA_ON            18
#define EE_OUT2_MINUTOS_ON         19
#define EE_OUT2_DIA_ON             20
#define EE_OUT3_HORA_ON            21
#define EE_OUT3_MINUTOS_ON         22
#define EE_OUT3_DIA_ON             23
#define EE_OUT4_HORA_ON            24
#define EE_OUT4_MINUTOS_ON         25
#define EE_OUT4_DIA_ON             26
#define EE_OUT5_HORA_ON            27
#define EE_OUT5_MINUTOS_ON         28
#define EE_OUT5_DIA_ON             29
#define EE_OUT6_HORA_ON            30
#define EE_OUT6_MINUTOS_ON         31
#define EE_OUT6_DIA_ON             32
#define EE_OUT7_HORA_ON            33
#define EE_OUT7_MINUTOS_ON         34
#define EE_OUT7_DIA_ON             35
#define EE_OUT8_HORA_ON            36
#define EE_OUT8_MINUTOS_ON         37
#define EE_OUT8_DIA_ON             38
#define EE_SALIDAS_RELOJ_OFF       39 
#define EE_OUT1_HORA_OFF           40
#define EE_OUT1_MINUTOS_OFF        41
#define EE_OUT1_DIA_OFF            42
#define EE_OUT2_HORA_OFF           43
#define EE_OUT2_MINUTOS_OFF        44
#define EE_OUT2_DIA_OFF            45
#define EE_OUT3_HORA_OFF           46
#define EE_OUT3_MINUTOS_OFF        47
#define EE_OUT3_DIA_OFF            48
#define EE_OUT4_HORA_OFF           49
#define EE_OUT4_MINUTOS_OFF        50
#define EE_OUT4_DIA_OFF            51
#define EE_OUT5_HORA_OFF           52
#define EE_OUT5_MINUTOS_OFF        53
#define EE_OUT5_DIA_OFF            54
#define EE_OUT6_HORA_OFF           55
#define EE_OUT6_MINUTOS_OFF        56
#define EE_OUT6_DIA_OFF            57
#define EE_OUT7_HORA_OFF           58
#define EE_OUT7_MINUTOS_OFF        59
#define EE_OUT7_DIA_OFF            60
#define EE_OUT8_HORA_OFF           61
#define EE_OUT8_MINUTOS_OFF        62
#define EE_OUT8_DIA_OFF            63
#define EE_GWIP_BYTE_1              64
#define EE_GWIP_BYTE_2              65
#define EE_GWIP_BYTE_3              66
#define EE_GWIP_BYTE_4              67
#define EE_MAC_BYTE_1              68
#define EE_MAC_BYTE_2              68
#define EE_MAC_BYTE_3              68
#define EE_MAC_BYTE_4              68
#define EE_MAC_BYTE_5              68
#define EE_MAC_BYTE_6              69
        

bool PROGRAMACION=0;
bool bG_PrimeraEntrada;  
bool OUT1_Temporizada;
bool OUT2_Temporizada;
bool OUT3_Temporizada;
bool OUT4_Temporizada;
bool OUT5_Temporizada;
bool OUT6_Temporizada;
bool OUT7_Temporizada;
bool OUT8_Temporizada;

bool OUT1_RELOJ_ON;
bool OUT2_RELOJ_ON;
bool OUT3_RELOJ_ON;
bool OUT4_RELOJ_ON;
bool OUT5_RELOJ_ON;
bool OUT6_RELOJ_ON;
bool OUT7_RELOJ_ON;
bool OUT8_RELOJ_ON;

bool OUT1_RELOJ_OFF;
bool OUT2_RELOJ_OFF;
bool OUT3_RELOJ_OFF;
bool OUT4_RELOJ_OFF;
bool OUT5_RELOJ_OFF;
bool OUT6_RELOJ_OFF;
bool OUT7_RELOJ_OFF;
bool OUT8_RELOJ_OFF;

bool OUT1_CONDICION_ON;
bool OUT2_CONDICION_ON;
bool OUT3_CONDICION_ON;
bool OUT4_CONDICION_ON;
bool OUT5_CONDICION_ON;
bool OUT6_CONDICION_ON;
bool OUT7_CONDICION_ON;
bool OUT8_CONDICION_ON;

bool OUT1_CONDICION_OFF;
bool OUT2_CONDICION_OFF;
bool OUT3_CONDICION_OFF;
bool OUT4_CONDICION_OFF;
bool OUT5_CONDICION_OFF;
bool OUT6_CONDICION_OFF;
bool OUT7_CONDICION_OFF;
bool OUT8_CONDICION_OFF;

unsigned char TIEMPO_TEMPORIZADA_OUT1;
unsigned char TIEMPO_TEMPORIZADA_OUT2;
unsigned char TIEMPO_TEMPORIZADA_OUT3;
unsigned char TIEMPO_TEMPORIZADA_OUT4;
unsigned char TIEMPO_TEMPORIZADA_OUT5;
unsigned char TIEMPO_TEMPORIZADA_OUT6;
unsigned char TIEMPO_TEMPORIZADA_OUT7;
unsigned char TIEMPO_TEMPORIZADA_OUT8;


unsigned char OUT1_HORA_ON ;
unsigned char OUT1_MINUTOS_ON;
unsigned char OUT1_DIA_ON; 
unsigned char OUT2_HORA_ON ;
unsigned char OUT2_MINUTOS_ON;
unsigned char OUT2_DIA_ON; 
unsigned char OUT3_HORA_ON ;
unsigned char OUT3_MINUTOS_ON;
unsigned char OUT3_DIA_ON; 
unsigned char OUT4_HORA_ON ;
unsigned char OUT4_MINUTOS_ON;
unsigned char OUT4_DIA_ON; 
unsigned char OUT5_HORA_ON ;
unsigned char OUT5_MINUTOS_ON;
unsigned char OUT5_DIA_ON; 
unsigned char OUT6_HORA_ON ;
unsigned char OUT6_MINUTOS_ON;
unsigned char OUT6_DIA_ON; 
unsigned char OUT7_HORA_ON ;
unsigned char OUT7_MINUTOS_ON;
unsigned char OUT7_DIA_ON; 
unsigned char OUT8_HORA_ON ;
unsigned char OUT8_MINUTOS_ON;
unsigned char OUT8_DIA_ON; 

unsigned char OUT1_HORA_OFF ;
unsigned char OUT1_MINUTOS_OFF;
unsigned char OUT1_DIA_OFF; 
unsigned char OUT2_HORA_OFF ;
unsigned char OUT2_MINUTOS_OFF;
unsigned char OUT2_DIA_OFF; 
unsigned char OUT3_HORA_OFF ;
unsigned char OUT3_MINUTOS_OFF;
unsigned char OUT3_DIA_OFF; 
unsigned char OUT4_HORA_OFF ;
unsigned char OUT4_MINUTOS_OFF;
unsigned char OUT4_DIA_OFF; 
unsigned char OUT5_HORA_OFF ;
unsigned char OUT5_MINUTOS_OFF;
unsigned char OUT5_DIA_OFF; 
unsigned char OUT6_HORA_OFF ;
unsigned char OUT6_MINUTOS_OFF;
unsigned char OUT6_DIA_OFF; 
unsigned char OUT7_HORA_OFF ;
unsigned char OUT7_MINUTOS_OFF;
unsigned char OUT7_DIA_OFF; 
unsigned char OUT8_HORA_OFF ;
unsigned char OUT8_MINUTOS_OFF;
unsigned char OUT8_DIA_OFF; 


byte data[3];
byte Data2 [62];
byte bufer[2];
const unsigned int Longitud = 62;
unsigned int timer1seg;
unsigned int timer_OUT1;
unsigned int timer_OUT2;
unsigned int timer_OUT3;
unsigned int timer_OUT4;
unsigned int timer_OUT5;
unsigned int timer_OUT6;
unsigned int timer_OUT7;
unsigned int timer_OUT8;

unsigned char GET_ENTRADAS_DIGITALES=0;
unsigned char POST_SALIDAS_DIGITALES=0;
unsigned char SALIDAS_TEMPORIZADAS;
unsigned char SALIDAS_RELOJ_ON;
unsigned char SALIDAS_RELOJ_OFF;  


// RTC_DS1307 rtc;
RTC_DS3231 rtc;
 
String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };

static byte mac[] = {0x00,0x01,0x02,0x03,0x04,0x05};
static byte ip[] =   {192,168,0,90};
static byte gwip[] = { 192,168,0,1 };
byte Ethernet::buffer[200];
BufferFiller bfill;


void setup () 
{

     Timer1.initialize(1000000);                   // Dispara cada 1000 ms
     Timer1.attachInterrupt(Timer1000ms);           // Activa la interrupcion y la asocia a Timer100ms 
     Serial.begin(115200);
     InicializarVariables();
     ether.begin(sizeof Ethernet::buffer, mac, 10); //configura modulo ethernet
     ether.staticSetup(ip);//establece la ip
     if (!rtc.begin()) // si devuelve 0 falla de ocomunicacion RTC
      {
      Serial.println(F("Couldn't find RTC"));    
      }
    delay(1000); 
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));// Fijar a fecha y hora de compilacion
   // rtc.adjust(DateTime(2016, 1, 21, 3, 10, 10)); // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
   
  //------Configuracion de salidas digitales
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT);
  pinMode(OUT6, OUTPUT);
  pinMode(OUT7, OUTPUT);
  pinMode(OUT8, OUTPUT);
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, LOW);
  digitalWrite(OUT3, LOW);
  digitalWrite(OUT4, LOW);
  digitalWrite(OUT5, HIGH);// LOS RELES SE ACTIVAN CON UN 0
  digitalWrite(OUT6, HIGH);// LOS RELES SE ACTIVAN CON UN 0
  digitalWrite(OUT7, HIGH);// LOS RELES SE ACTIVAN CON UN 0
  digitalWrite(OUT8, HIGH);// LOS RELES SE ACTIVAN CON UN 0

  //Configuracion de entradas digitales
  pinMode(IN1, INPUT_PULLUP);
  pinMode(IN2, INPUT_PULLUP);
  pinMode(IN3, INPUT_PULLUP);
  pinMode(IN4, INPUT_PULLUP);
  bG_PrimeraEntrada = true;
 

}

void loop() 
{

   DateTime now = rtc.now();
  //printDate(now); //IMPRIME LA HORA
  
 if(PROGRAMACION == OFF) // SI MODO PROGRAMACION ESTA DESACTIVADO ENTRA
    {
   if(bG_PrimeraEntrada == true)  // PRIMERA ENTRADA PARA INICIALIZAR VARIABLES
    { 
     wdt_disable();//DESACTIVO PERRO GUARDION
     bG_PrimeraEntrada = false;
     InicializarVariables();
    }
  
    word rec = ether.packetReceive();
    word pack = ether.packetLoop(rec);
  
  if(pack) 
  {
    if(strstr((char *)Ethernet::buffer + pack, "GET /IN1/ESTADO") != 0) 
    {
       GET_ENTRADAS_DIGITALES = 1;      
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "GET /IN2/ESTADO") != 0) 
    {
       GET_ENTRADAS_DIGITALES = 2;  
      
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "GET /IN3/ESTADO") != 0) 
    {
       GET_ENTRADAS_DIGITALES = 3;     
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "GET /IN4/ESTADO") != 0) 
    {
       GET_ENTRADAS_DIGITALES = 4;     
    }
    //ENTRADAS ANALOGICAS
      else  if(strstr((char *)Ethernet::buffer + pack, "GET /INA1/VALOR") != 0) 
    {
       GET_ENTRADAS_DIGITALES = 5;     
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "GET /INA2/VALOR") != 0) 
    {
       GET_ENTRADAS_DIGITALES = 6;     
    }
  // SALIDAS DIGITALES ON

    else if(strstr((char *)Ethernet::buffer + pack, "POST /OUT1/ON") != 0) 
    {
       Serial.println(strstr((char *)Ethernet::buffer + pack, "POST /OUT1/ON") );
       POST_SALIDAS_DIGITALES = 1; 
       
       if (OUT1_Temporizada == true);
          {
          timer_OUT1 = 0;
          }
            
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT2/ON") != 0) 
    {
       POST_SALIDAS_DIGITALES = 2;  

      if (OUT2_Temporizada == true);
          {
          timer_OUT2 = 0;
          }
            
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT3/ON") != 0) 
    {
       POST_SALIDAS_DIGITALES = 3;  
        
       if (OUT3_Temporizada == true);
          {
          timer_OUT3 = 0;
          }
              
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT4/ON") != 0) 
    {
       POST_SALIDAS_DIGITALES = 4;   

        if (OUT4_Temporizada == true);
          {
          timer_OUT4 = 0;
          }
            
    }

           else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT5/ON") != 0) 
    {
       POST_SALIDAS_DIGITALES = 5;   

        if (OUT5_Temporizada == true);
          {
          timer_OUT5 = 0;
          }
            
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT6/ON") != 0) 
    {
       POST_SALIDAS_DIGITALES = 6;   

        if (OUT6_Temporizada == true);
          {
          timer_OUT6 = 0;
          }
            
    }

       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT7/ON") != 0) 
    {
       POST_SALIDAS_DIGITALES = 7;   

        if (OUT7_Temporizada == true);
          {
          timer_OUT7 = 0;
          }
            
    }

       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT8/ON") != 0) 
    {
       POST_SALIDAS_DIGITALES = 8;   

        if (OUT8_Temporizada == true);
          {
          timer_OUT8 = 0;
          }
            
    }

    
  // SALIDAS DIGITALES OFF
      
     else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT1/OFF") != 0) 
    {
       POST_SALIDAS_DIGITALES = 9;     
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT2/OFF") != 0) 
    {
       POST_SALIDAS_DIGITALES = 10;     
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT3/OFF") != 0) 
    {
       POST_SALIDAS_DIGITALES = 11;     
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT4/OFF") != 0) 
    {
       POST_SALIDAS_DIGITALES = 12;     
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT5/OFF") != 0) 
    {
       POST_SALIDAS_DIGITALES = 13;     
    }
           else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT6/OFF") != 0) 
    {
       POST_SALIDAS_DIGITALES = 14;     
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT7/OFF") != 0) 
    {
       POST_SALIDAS_DIGITALES = 15;     
    }
       else  if(strstr((char *)Ethernet::buffer + pack, "POST /OUT8/OFF") != 0) 
    {
       POST_SALIDAS_DIGITALES = 16;     
    }

    
   else 
   {
     GET_ENTRADAS_DIGITALES = 0;  
   }
     }
    if(pack) 
      {
      ether.httpServerReply(homePage());
      }



//VAMOS A LEER BIT DE UNA CHAR


if (bitRead(SALIDAS_TEMPORIZADAS, 0)== 1)  // bit 0

 {
  OUT1_Temporizada = true;
 }else {
  OUT1_Temporizada = false;
 }

 if (bitRead(SALIDAS_TEMPORIZADAS, 1)== 1) // bit 1

 {
  OUT2_Temporizada = true;
 }else {
  OUT2_Temporizada = false;
 }

 if (bitRead(SALIDAS_TEMPORIZADAS, 2)== 1) // bit 2

 {
  OUT3_Temporizada = true;
 }else {
  OUT3_Temporizada = false;
 }

  if (bitRead(SALIDAS_TEMPORIZADAS, 3)== 1)  // bit 3

 {
  OUT4_Temporizada = true;
 }else {
  OUT4_Temporizada = false;
 }

   if (bitRead(SALIDAS_TEMPORIZADAS, 4)== 1)  // bit 4

 {
  OUT5_Temporizada = true;
 }else {
  OUT5_Temporizada = false;
 }

  if (bitRead(SALIDAS_TEMPORIZADAS, 5)== 1)  // bit 5

 {
  OUT6_Temporizada = true;
 }else {
  OUT6_Temporizada = false;
 }

   if (bitRead(SALIDAS_TEMPORIZADAS, 6)== 1)  // bit 6

 {
  OUT7_Temporizada = true;
 }else {
  OUT7_Temporizada = false;
 }

   if (bitRead(SALIDAS_TEMPORIZADAS, 7)== 1)  // bit 7

 {
  OUT8_Temporizada = true;
 }else {
  OUT8_Temporizada = false;
 }

    if (timer_OUT1 > TIEMPO_TEMPORIZADA_OUT1  && OUT1_Temporizada == true)
  {
   digitalWrite (OUT1, LOW);
   timer_OUT1 = 0; 
  }
      if (timer_OUT2 > TIEMPO_TEMPORIZADA_OUT2  && OUT2_Temporizada == true)
  {
   digitalWrite (OUT2, LOW);
   timer_OUT2 = 0; 
  }
      if (timer_OUT3 > TIEMPO_TEMPORIZADA_OUT3 && OUT3_Temporizada == true)
  {
   digitalWrite (OUT3, LOW);
   timer_OUT3 = 0; 
  }

   if (timer_OUT4 > TIEMPO_TEMPORIZADA_OUT4  && OUT4_Temporizada == true)
  {
   digitalWrite (OUT4, LOW);
   timer_OUT4 = 0; 
  }
   if (timer_OUT5 > TIEMPO_TEMPORIZADA_OUT5  && OUT5_Temporizada == true)
  {
   digitalWrite (OUT5, HIGH);
   timer_OUT5 = 0; 
  }
   if (timer_OUT6 > TIEMPO_TEMPORIZADA_OUT6  && OUT6_Temporizada == true)
  {
   digitalWrite (OUT6, HIGH);
   timer_OUT6 = 0; 
  }
   if (timer_OUT7 > TIEMPO_TEMPORIZADA_OUT7  && OUT7_Temporizada == true)
  {
   digitalWrite (OUT7, HIGH);
   timer_OUT7 = 0; 
  }
   if (timer_OUT8 > TIEMPO_TEMPORIZADA_OUT8  && OUT8_Temporizada == true)
  {
   digitalWrite (OUT8, HIGH);
   timer_OUT8 = 0; 
  }  


//VAMOS A LEER BIT DE UN CHAR


if (bitRead(SALIDAS_RELOJ_ON, 0)== 1)  // bit 0

 {
  OUT1_RELOJ_ON = true;
 }else {
  OUT1_RELOJ_ON = false;
 }

if (bitRead(SALIDAS_RELOJ_ON, 1)== 1)  // bit 1

 {
  OUT2_RELOJ_ON = true;
 }else {
  OUT2_RELOJ_ON = false;
 }

if (bitRead(SALIDAS_RELOJ_ON, 2)== 1)  // bit 2

 {
  OUT3_RELOJ_ON = true;
 }else {
  OUT3_RELOJ_ON = false;
 }
if (bitRead(SALIDAS_RELOJ_ON, 3)== 1)  // bit 3

 {
  OUT4_RELOJ_ON = true;
 }else {
  OUT4_RELOJ_ON = false;
 }
if (bitRead(SALIDAS_RELOJ_ON, 4)== 1)  // bit 4

 {
  OUT5_RELOJ_ON = true;
 }else {
  OUT5_RELOJ_ON = false;
 }

if (bitRead(SALIDAS_RELOJ_ON, 5)== 1)  // bit 5

 {
  OUT6_RELOJ_ON = true;
 }else {
  OUT6_RELOJ_ON = false;
 }

 if (bitRead(SALIDAS_RELOJ_ON, 6)== 1)  // bit 6

 {
  OUT7_RELOJ_ON = true;
 }else {
  OUT7_RELOJ_ON = false;
 }

 if (bitRead(SALIDAS_RELOJ_ON, 7)== 1)  // bit 7

 {
  OUT8_RELOJ_ON = true;
 }else {
  OUT8_RELOJ_ON = false;
 }



   
if (OUT1_RELOJ_ON == true)  
   {
   salida_1(now);
   }

   if (OUT1_CONDICION_ON == true)  
   {
   digitalWrite(OUT1,HIGH);
   OUT1_CONDICION_ON = false;
   }

   
if (OUT2_RELOJ_ON == true)  
   {
   salida_2(now);
   }

   if (OUT2_CONDICION_ON == true)  
   {
   digitalWrite(OUT2,HIGH);
   OUT2_CONDICION_ON = false;
   }
if (OUT3_RELOJ_ON == true)  
   {
   salida_3(now);
   }

   if (OUT3_CONDICION_ON == true)  
   {
   digitalWrite(OUT3,HIGH);
   OUT3_CONDICION_ON = false;
   }

   if (OUT4_RELOJ_ON == true)  
   {
   salida_4(now);
   }

   if (OUT4_CONDICION_ON == true)  
   {
   digitalWrite(OUT4,HIGH);
   OUT4_CONDICION_ON = false;
   }

if (OUT5_RELOJ_ON == true)  
   {
   salida_5(now);
   }

   if (OUT5_CONDICION_ON == true)  
   {
   digitalWrite(OUT5,LOW);
   OUT5_CONDICION_ON = false;
   }

if (OUT6_RELOJ_ON == true)  
   {
   salida_6(now);
   }

   if (OUT6_CONDICION_ON == true)  
   {
   digitalWrite(OUT6,LOW);
   OUT6_CONDICION_ON = false;
   }

if (OUT7_RELOJ_ON == true)  
   {
   salida_7(now);
   }

   if (OUT7_CONDICION_ON == true)  
   {
   digitalWrite(OUT7,LOW);
   OUT7_CONDICION_ON = false;
   }

if (OUT8_RELOJ_ON == true)  
   {
   salida_8(now);
   }

   if (OUT8_CONDICION_ON == true)  
   {
   digitalWrite(OUT8,LOW);
   OUT8_CONDICION_ON = false;
   }


if (bitRead(SALIDAS_RELOJ_OFF, 0)== 1)  // bit 0

 {
  OUT1_RELOJ_OFF = true;
 }else {
  OUT1_RELOJ_OFF = false;
 }


if (bitRead(SALIDAS_RELOJ_OFF, 1)== 1)  // bit 1

 {
  OUT2_RELOJ_OFF = true;
 }else {
  OUT2_RELOJ_OFF = false;
 }

 
if (bitRead(SALIDAS_RELOJ_OFF, 2)== 1)  // bit 2

 {
  OUT3_RELOJ_OFF = true;
 }else {
  OUT3_RELOJ_OFF = false;
 }

 
if (bitRead(SALIDAS_RELOJ_OFF, 3)== 1)  // bit 3

 {
  OUT4_RELOJ_OFF = true;
 }else {
  OUT4_RELOJ_OFF = false;
 }

 
if (bitRead(SALIDAS_RELOJ_OFF, 4)== 1)  // bit 4

 {
  OUT5_RELOJ_OFF = true;
 }else {
  OUT5_RELOJ_OFF = false;
 }

 
if (bitRead(SALIDAS_RELOJ_OFF, 5)== 1)  // bit 5

 {
  OUT6_RELOJ_OFF = true;
 }else {
  OUT6_RELOJ_OFF = false;
 }

 
if (bitRead(SALIDAS_RELOJ_OFF, 6)== 1)  // bit 6

 {
  OUT7_RELOJ_OFF = true;
 }else {
  OUT7_RELOJ_OFF = false;
 }

 
if (bitRead(SALIDAS_RELOJ_OFF, 7)== 1)  // bit 7

 {
  OUT8_RELOJ_OFF = true;
 }else {
  OUT8_RELOJ_OFF = false;
 }

// SI ESTA ACTIVADA LA SALIDA PARA QUE SE DESACTIVE ENTRA EN LAS CONDICIONES

if (OUT1_RELOJ_OFF == true)  
   {
   salida_1_off(now);
   }

   if (OUT1_CONDICION_OFF == true)  
   {
   digitalWrite(OUT1,LOW);
   OUT1_CONDICION_OFF = false;
   }

   
if (OUT2_RELOJ_OFF == true)  
   {
   salida_2_off(now);
   }

   if (OUT2_CONDICION_OFF == true)  
   {
   digitalWrite(OUT2,LOW);
   OUT2_CONDICION_OFF = false;
   }
if (OUT3_RELOJ_OFF == true)  
   {
   salida_3_off(now);
   }

   if (OUT3_CONDICION_OFF == true)  
   {
   digitalWrite(OUT3,LOW);
   OUT3_CONDICION_OFF = false;
   }

   if (OUT4_RELOJ_OFF == true)  
   {
   salida_4_off(now);
   }

   if (OUT4_CONDICION_OFF == true)  
   {
   digitalWrite(OUT4,LOW);
   OUT4_CONDICION_OFF = false;
   }

if (OUT5_RELOJ_OFF == true)  
   {
   salida_5_off(now);
   }

   if (OUT5_CONDICION_OFF == true)  
   {
   digitalWrite(OUT5,HIGH);
   OUT5_CONDICION_OFF = false;
   }

if (OUT6_RELOJ_OFF == true)  
   {
   salida_6_off(now);
   }

   if (OUT6_CONDICION_OFF == true)  
   {
   digitalWrite(OUT6,HIGH);
   OUT6_CONDICION_OFF = false;
   }

if (OUT7_RELOJ_OFF == true)  
   {
   salida_7_off(now);
   }

   if (OUT7_CONDICION_OFF == true)  
   {
   digitalWrite(OUT7,HIGH);
   OUT7_CONDICION_OFF = false;
   }

if (OUT8_RELOJ_OFF == true)  
   {
   salida_8_off(now);
   }

   if (OUT8_CONDICION_OFF == true)  
   {
   digitalWrite(OUT8,HIGH);
   OUT8_CONDICION_OFF = false;
   }
  
}
    else
  {
    
   Programacion(); //llama a la funcion programacion y se queda ahi esta que cambia PROGRAMACION = 0;
   bG_PrimeraEntrada = true; // primera entrada true para que vuelva a configurar las variables leidas de eeprom
   wdt_enable(WDTO_15MS);
   delay(100);//activar DTW
   
  }   
}



void printDate(DateTime date)
{

    
   Serial.print(date.year(), DEC);
   Serial.print('/');
   Serial.print(date.month(), DEC);
   Serial.print('/');
   Serial.print(date.day(), DEC);
   Serial.print(" (");
   Serial.print(daysOfTheWeek[date.dayOfTheWeek()]);
   Serial.print(") ");
   Serial.print(date.hour(), DEC);
   Serial.print(':');
   Serial.print(date.minute(), DEC);
   Serial.print(':');
   Serial.print(date.second(), DEC);
   Serial.println();
}


void InicializarVariables(void)
{ 

 ip[0]= EEPROM.read(EE_IP_BYTE_1) ;
 ip[1]= EEPROM.read(EE_IP_BYTE_2) ;
 ip[2]= EEPROM.read(EE_IP_BYTE_3) ;
 ip[3]= EEPROM.read(EE_IP_BYTE_4) ;

// gwip[0]= EEPROM.read(EE_GWIP_BYTE_1);
// gwip[1]= EEPROM.read(EE_GWIP_BYTE_2);
// gwip[2]= EEPROM.read(EE_GWIP_BYTE_3);
// gwip[3]= EEPROM.read(EE_GWIP_BYTE_4);
//
// mac[0]= EEPROM.read(EE_MAC_BYTE_1);
// mac[1]= EEPROM.read(EE_MAC_BYTE_2);
// mac[2]= EEPROM.read(EE_MAC_BYTE_3);
// mac[3]= EEPROM.read(EE_MAC_BYTE_4);
// mac[4]= EEPROM.read(EE_MAC_BYTE_5);
// mac[5]= EEPROM.read(EE_MAC_BYTE_6);

//--------------LEE EL DE MODO DE ACTIVACION DE SALIDA POR TIMER-----------------------

SALIDAS_TEMPORIZADAS = EEPROM.read(EE_SALIDAS_TEMPORIZADAS);
//--------------LEE EL TIEMPO DE TEMPORIZADO DE CADA SALIDA-----------------------
TIEMPO_TEMPORIZADA_OUT1= EEPROM.read(EE_TIEMPO_TEMPORIZADA_OUT1);
TIEMPO_TEMPORIZADA_OUT2= EEPROM.read(EE_TIEMPO_TEMPORIZADA_OUT2);
TIEMPO_TEMPORIZADA_OUT3= EEPROM.read(EE_TIEMPO_TEMPORIZADA_OUT3);
TIEMPO_TEMPORIZADA_OUT4= EEPROM.read(EE_TIEMPO_TEMPORIZADA_OUT4);
TIEMPO_TEMPORIZADA_OUT5= EEPROM.read(EE_TIEMPO_TEMPORIZADA_OUT5);
TIEMPO_TEMPORIZADA_OUT6= EEPROM.read(EE_TIEMPO_TEMPORIZADA_OUT6);
TIEMPO_TEMPORIZADA_OUT7= EEPROM.read(EE_TIEMPO_TEMPORIZADA_OUT7);
TIEMPO_TEMPORIZADA_OUT8= EEPROM.read(EE_TIEMPO_TEMPORIZADA_OUT8);

//--------------LEE EL MODO DE ACTIVACION DE LAS SALIDAS POR HORA Y DIA -----------------------

SALIDAS_RELOJ_ON = EEPROM.read(EE_SALIDAS_RELOJ_ON);

//--------------LEE EL LA HORA, MINUTOS Y  DIA DE ACTIVACION DE SALIDAS -----------------------

OUT1_HORA_ON =    EEPROM.read(EE_OUT1_HORA_ON);
OUT1_MINUTOS_ON = EEPROM.read(EE_OUT1_MINUTOS_ON);
OUT1_DIA_ON =     EEPROM.read(EE_OUT1_DIA_ON);

OUT2_HORA_ON =    EEPROM.read(EE_OUT2_HORA_ON);
OUT2_MINUTOS_ON = EEPROM.read(EE_OUT2_MINUTOS_ON);
OUT2_DIA_ON =     EEPROM.read(EE_OUT2_DIA_ON);

OUT3_HORA_ON =    EEPROM.read(EE_OUT3_HORA_ON);
OUT3_MINUTOS_ON = EEPROM.read(EE_OUT3_MINUTOS_ON);
OUT3_DIA_ON =     EEPROM.read(EE_OUT3_DIA_ON);

OUT4_HORA_ON =    EEPROM.read(EE_OUT4_HORA_ON);
OUT4_MINUTOS_ON = EEPROM.read(EE_OUT4_MINUTOS_ON);
OUT4_DIA_ON =     EEPROM.read(EE_OUT4_DIA_ON);

OUT5_HORA_ON =    EEPROM.read(EE_OUT5_HORA_ON);
OUT5_MINUTOS_ON = EEPROM.read(EE_OUT5_MINUTOS_ON);
OUT5_DIA_ON =     EEPROM.read(EE_OUT5_DIA_ON);

OUT6_HORA_ON =    EEPROM.read(EE_OUT6_HORA_ON);
OUT6_MINUTOS_ON = EEPROM.read(EE_OUT6_MINUTOS_ON);
OUT6_DIA_ON =     EEPROM.read(EE_OUT6_DIA_ON);

OUT7_HORA_ON =    EEPROM.read(EE_OUT7_HORA_ON);
OUT7_MINUTOS_ON = EEPROM.read(EE_OUT7_MINUTOS_ON);
OUT7_DIA_ON =     EEPROM.read(EE_OUT7_DIA_ON);

OUT8_HORA_ON =    EEPROM.read(EE_OUT8_HORA_ON);
OUT8_MINUTOS_ON = EEPROM.read(EE_OUT8_MINUTOS_ON);
OUT8_DIA_ON =     EEPROM.read(EE_OUT8_DIA_ON);

//--------------LEE EL MODO DE DESACTIVACION DE LAS SALIDAS POR HORA Y DIA -----------------------

SALIDAS_RELOJ_OFF = EEPROM.read(EE_SALIDAS_RELOJ_OFF);

//--------------LEE EL LA HORA, MINUTOS Y  DIA DE DESACTIVACION DE SALIDAS -----------------------

OUT1_HORA_OFF =    EEPROM.read(EE_OUT1_HORA_OFF);
OUT1_MINUTOS_OFF = EEPROM.read(EE_OUT1_MINUTOS_OFF);
OUT1_DIA_OFF =     EEPROM.read(EE_OUT1_DIA_OFF);

OUT2_HORA_OFF =    EEPROM.read(EE_OUT2_HORA_OFF);
OUT2_MINUTOS_OFF = EEPROM.read(EE_OUT2_MINUTOS_OFF);
OUT2_DIA_OFF =     EEPROM.read(EE_OUT2_DIA_OFF);

OUT3_HORA_OFF =    EEPROM.read(EE_OUT3_HORA_OFF);
OUT3_MINUTOS_OFF = EEPROM.read(EE_OUT3_MINUTOS_OFF);
OUT3_DIA_OFF =     EEPROM.read(EE_OUT3_DIA_OFF);

OUT4_HORA_OFF =    EEPROM.read(EE_OUT4_HORA_OFF);
OUT4_MINUTOS_OFF = EEPROM.read(EE_OUT4_MINUTOS_OFF);
OUT4_DIA_OFF =     EEPROM.read(EE_OUT4_DIA_OFF);

OUT5_HORA_OFF =    EEPROM.read(EE_OUT5_HORA_OFF);
OUT5_MINUTOS_OFF = EEPROM.read(EE_OUT5_MINUTOS_OFF);
OUT5_DIA_OFF =     EEPROM.read(EE_OUT5_DIA_OFF);

OUT6_HORA_OFF =    EEPROM.read(EE_OUT6_HORA_OFF);
OUT6_MINUTOS_OFF = EEPROM.read(EE_OUT6_MINUTOS_OFF);
OUT6_DIA_OFF =     EEPROM.read(EE_OUT6_DIA_OFF);

OUT7_HORA_OFF =    EEPROM.read(EE_OUT7_HORA_OFF);
OUT7_MINUTOS_OFF = EEPROM.read(EE_OUT7_MINUTOS_OFF);
OUT7_DIA_OFF =     EEPROM.read(EE_OUT7_DIA_OFF);

OUT8_HORA_OFF =    EEPROM.read(EE_OUT8_HORA_OFF);
OUT8_MINUTOS_OFF = EEPROM.read(EE_OUT8_MINUTOS_OFF);
OUT8_DIA_OFF =     EEPROM.read(EE_OUT8_DIA_OFF);

 return;
}


void Programacion(void)
{
  while(PROGRAMACION == ON)
  {  
   while (Serial.available()>0) 
       {      
          delay(1000);      
          Serial.readBytes(Data2, 62); 
         //delay(2000);                    
         if ( Data2[0]== 3)
           {
              if( Data2[1]== 3)
               {    
                  switch (Data2[2])
                  { 
                     case 1: // SE CONECTA AL EQUIPO Y ENVIA LOS DATOS A LA INTERFAZ
                      {
                      Enviar_Datos ();                 
                      break;            
                      }
                     case 2: // cambiar direccion IP,GIP Y MAC.
                     {  
                      EEPROM.write(EE_IP_BYTE_1,data[3]);            
                      EEPROM.write(EE_IP_BYTE_2,data[4]);
                      EEPROM.write(EE_IP_BYTE_3,data[5]);
                      EEPROM.write(EE_IP_BYTE_4,data[6]);
                      EEPROM.write(EE_GWIP_BYTE_1,data[7]);
                      EEPROM.write(EE_GWIP_BYTE_2,data[8]);
                      EEPROM.write(EE_GWIP_BYTE_3,data[9]);
                      EEPROM.write(EE_GWIP_BYTE_4,data[10]);
                      EEPROM.write(EE_MAC_BYTE_1,data[11]);
                      EEPROM.write(EE_MAC_BYTE_2,data[12]);
                      EEPROM.write(EE_MAC_BYTE_3,data[13]);
                      EEPROM.write(EE_MAC_BYTE_4,data[14]);
                      EEPROM.write(EE_MAC_BYTE_5,data[15]);
                      EEPROM.write(EE_MAC_BYTE_6,data[16]);                      
                      Serial.write(2);     //IP CAMBIADA                        
                       break;            
                      }
                       case 3:
                       {           
                        PROGRAMACION = false; //Desconectarse del equipo
                        Serial.write(3);              
                        break;                         
                       }
          
                       case 4: // Grabar Datos EEPROM SALIDAS TEMPORIZADAS
                       {  
                        Grabar_Datos_EEPROM_TEMP();
                        Serial.write(4);                                           
                        break;                         
                       }
                       case 5: // Grabar Datos EEPROM SALIDAS OFF POR RELOJ
                       {  
                        Grabar_Datos_EEPROM_OFF();
                        Serial.write(4);                                           
                        break;                         
                       }
                       case 6: // Grabar Datos EEPROM SALIDAS ON POR RELOJ
                       {  
                        Grabar_Datos_EEPROM_ON();
                        Serial.write(4);                                           
                        break;                         
                       }
                       case 7: //Actualizar fecha y hora RTC
                        {  
                         byte year2         = data[3]; 
                         byte year1         = data[4];    
                         byte me            = data[5]; 
                         byte di            = data[6];          
                         byte hor           = data[7];   
                         byte minu          = data[8]; 
                         byte segun         = data[9]; 
                         byte  recibe [2]   = {year2, year1};                           
                         unsigned int YEAR;
                         ObtenerValor(recibe, 0);     
                         rtc.adjust(DateTime( ObtenerValor(recibe, 0) , me,di,hor,minu,segun));
                         Serial.write(5);                                
                         break;   
                                                
                      }
                     }
                    }
                   }  
                  }       
                 }

 } 

unsigned int ObtenerValor(byte paquete [], byte i)
{

  unsigned int valor;
  valor = (valor * 256)+ paquete [i];
  valor = (valor * 256)+ paquete [i+1];
  return valor;
}

  void serialEvent()
{
    
     while (Serial.available()>0) 
      { 
        Serial.readBytes(data, 3);
          if ( data[0]== 3)
            {
              if( data[1]== 3)
                {    
                  if (data[2]=1)
                   { 
                        Enviar_Datos();
                        PROGRAMACION = true;       
                   }
              }
         }     
   } 
}


 void Timer1000ms(void)
  {
    timer1seg++;
    timer_OUT1++;
    timer_OUT2++;
    timer_OUT3++;
    timer_OUT4++;
    timer_OUT5++;
    timer_OUT6++;
    timer_OUT7++;
    timer_OUT8++;
  }


void Enviar_Datos(void)
{
  DateTime now = rtc.now();
                  
                     Serial.write(CONFIRMACION);
                     delay(100);
                     Serial.write(ip[0]);
                     delay(100);
                     Serial.write(ip[1]);
                     delay(100);
                     Serial.write(ip[2]);
                     delay(100);
                     Serial.write(ip[3]);
                     delay(100);
                     Serial.write(SALIDAS_TEMPORIZADAS);
                     delay(100);                    
                     Serial.write(TIEMPO_TEMPORIZADA_OUT1);
                     delay(100);
                     Serial.write(TIEMPO_TEMPORIZADA_OUT2);
                     delay(100);
                     Serial.write(TIEMPO_TEMPORIZADA_OUT3);
                     delay(100);
                     Serial.write(TIEMPO_TEMPORIZADA_OUT4);
                     delay(100);
                     Serial.write(TIEMPO_TEMPORIZADA_OUT5);
                     delay(100);
                     Serial.write(TIEMPO_TEMPORIZADA_OUT6);
                     delay(100);
                     Serial.write(TIEMPO_TEMPORIZADA_OUT7);
                     delay(100);
                     Serial.write(TIEMPO_TEMPORIZADA_OUT8);
                     delay(100);
                     Serial.write(SALIDAS_RELOJ_ON);
                     delay(100);
                     Serial.write(OUT1_HORA_ON);
                     delay(100);
                     Serial.write(OUT1_MINUTOS_ON);
                     delay(100);
                     Serial.write(OUT1_DIA_ON);
                     delay(100);
                     Serial.write(OUT2_HORA_ON);
                     delay(100);
                     Serial.write(OUT2_MINUTOS_ON);
                     delay(100);
                     Serial.write(OUT2_DIA_ON);
                     delay(100);
                     Serial.write(OUT3_HORA_ON);
                     delay(100);
                     Serial.write(OUT3_MINUTOS_ON);
                     delay(100);
                     Serial.write(OUT3_DIA_ON);
                     delay(100);
                     Serial.write(OUT4_HORA_ON);
                     delay(100);
                     Serial.write(OUT4_MINUTOS_ON);
                     delay(100);
                     Serial.write(OUT4_DIA_ON);
                     delay(100);
                     Serial.write(OUT5_HORA_ON);
                     delay(100);
                     Serial.write(OUT5_MINUTOS_ON);
                     delay(100);
                     Serial.write(OUT5_DIA_ON);
                     delay(100);
                     Serial.write(OUT6_HORA_ON);
                     delay(100);
                     Serial.write(OUT6_MINUTOS_ON);
                     delay(100);
                     Serial.write(OUT6_DIA_ON);
                     delay(100);
                     Serial.write(OUT7_HORA_ON);
                     delay(100);
                     Serial.write(OUT7_MINUTOS_ON);
                     delay(100);
                     Serial.write(OUT7_DIA_ON);
                     delay(100);
                     Serial.write(OUT8_HORA_ON);
                     delay(100);
                     Serial.write(OUT8_MINUTOS_ON);
                     delay(100);
                     Serial.write(OUT8_DIA_ON);
                     delay(100);                    
                     Serial.write(SALIDAS_RELOJ_OFF);
                     delay(100);                    
                     Serial.write(OUT1_HORA_OFF);
                     delay(100);
                     Serial.write(OUT1_MINUTOS_OFF);
                     delay(100);
                     Serial.write(OUT1_DIA_OFF);
                     delay(100);
                     Serial.write(OUT2_HORA_OFF);
                     delay(100);
                     Serial.write(OUT2_MINUTOS_OFF);
                     delay(100);
                     Serial.write(OUT2_DIA_OFF);
                     delay(100);
                     Serial.write(OUT3_HORA_OFF);
                     delay(100);
                     Serial.write(OUT3_MINUTOS_OFF);
                     delay(100);
                     Serial.write(OUT3_DIA_OFF);
                     delay(100);
                     Serial.write(OUT4_HORA_OFF);
                     delay(100);
                     Serial.write(OUT4_MINUTOS_OFF);
                     delay(100);
                     Serial.write(OUT4_DIA_OFF);
                     delay(100);
                     Serial.write(OUT5_HORA_OFF);
                     delay(100);
                     Serial.write(OUT5_MINUTOS_OFF);
                     delay(100);
                     Serial.write(OUT5_DIA_OFF);
                     delay(100);
                     Serial.write(OUT6_HORA_OFF);
                     delay(100);
                     Serial.write(OUT6_MINUTOS_OFF);
                     delay(100);
                     Serial.write(OUT6_DIA_OFF);
                     delay(100);
                     Serial.write(OUT7_HORA_OFF);
                     delay(100);
                     Serial.write(OUT7_MINUTOS_OFF);
                     delay(100);
                     Serial.write(OUT7_DIA_OFF);
                     delay(100);
                     Serial.write(OUT8_HORA_OFF);
                     delay(100);
                     Serial.write(OUT8_MINUTOS_OFF);
                     delay(100);
                     Serial.write(OUT8_DIA_OFF);
                     delay(100);
                     Enviar_Hora(now);    //71 bytes  
                     delay(100);
                     Serial.write(gwip[0]);
                     delay(100);
                     Serial.write(gwip[1]);
                     delay(100);
                     Serial.write(gwip[2]);
                     delay(100);
                     Serial.write(gwip[3]);
                     delay(100);
                     Serial.write(mac[0]);
                     delay(100);
                     Serial.write(mac[1]);
                     delay(100);
                     Serial.write(mac[2]);
                     delay(100);
                     Serial.write(mac[3]);
                     delay(100);
                     Serial.write(mac[4]);
                     delay(100);
                     Serial.write(mac[5]); //81
                                                   
}


 void Enviar_Hora (DateTime date)
{

 int Ano = date.year(); 
 int Mes = date.month();
 int Dia = date.day();  
 int Dia_Semana = date.dayOfTheWeek(); 
 int Hora = date.hour(); 
 int Minutos = date.minute(); 
 int Segundos = date.second(); 

//  byte *bufer;
//  byte *pointer = (byte*)&Ano;
//  for (byte i = 0; i < 2; i++) 
//  {
//    bufer[i] = pointer[i];
// }

 byte ANO1;
 byte ANO2;
 ANO1 = Ano & 0XFF;
 ANO2 = Ano >>8&0XFF;

 Serial.write(ANO2);
 delay(100);
 Serial.write(ANO1);
 delay(100);
 Serial.write(Mes);
 delay(100);
 Serial.write(Dia);
 delay(100);
 Serial.write(Hora);
 delay(100);
 Serial.write(Minutos);
 delay(100);
 Serial.write(Segundos);

}


void Grabar_Datos_EEPROM_TEMP(void)

{             
          
             EEPROM.write(EE_SALIDAS_TEMPORIZADAS,   data[3]);    //OUT1 1 = SALIDA ACTIVA CON TEMPORIZADOR             
             EEPROM.write(EE_TIEMPO_TEMPORIZADA_OUT1,data[4]); // TIEMPO TEMPORIZADA OUT 1, EN SEGUNDOS, MAXIMO 254 SEGUNDOS
             EEPROM.write(EE_TIEMPO_TEMPORIZADA_OUT2,data[5]); // TIEMPO TEMPORIZADA OUT 2, EN SEGUNDOS, MAXIMO 254 SEGUNDOS
             EEPROM.write(EE_TIEMPO_TEMPORIZADA_OUT3,data[6]); // TIEMPO TEMPORIZADA OUT 3, EN SEGUNDOS, MAXIMO 254 SEGUNDOS
             EEPROM.write(EE_TIEMPO_TEMPORIZADA_OUT4,data[7]); // TIEMPO TEMPORIZADA OUT 4, EN SEGUNDOS, MAXIMO 254 SEGUNDOS
             EEPROM.write(EE_TIEMPO_TEMPORIZADA_OUT5,data[8]); // TIEMPO TEMPORIZADA OUT 5, EN SEGUNDOS, MAXIMO 254 SEGUNDOS
             EEPROM.write(EE_TIEMPO_TEMPORIZADA_OUT6,data[9]); // TIEMPO TEMPORIZADA OUT 6, EN SEGUNDOS, MAXIMO 254 SEGUNDOS
             EEPROM.write(EE_TIEMPO_TEMPORIZADA_OUT7,data[10]); // TIEMPO TEMPORIZADA OUT 7, EN SEGUNDOS, MAXIMO 254 SEGUNDOS
             EEPROM.write(EE_TIEMPO_TEMPORIZADA_OUT8,data[11]); // TIEMPO TEMPORIZADA OUT 8, EN SEGUNDOS, MAXIMO 254 SEGUNDOS     
             return;
             
}
void Grabar_Datos_EEPROM_ON(void)

{             
          
             EEPROM.write(EE_SALIDAS_RELOJ_ON,data[3]); //OUT1 = SALIDA ACTIVA CON HORA DEL RELOJ
             EEPROM.write(EE_OUT1_HORA_ON ,   data[4]); //OUT1 = HORA DE ENCENDIDA 
             EEPROM.write(EE_OUT1_MINUTOS_ON ,data[5]); //OUT1 = MINUTOS DE ENCENDIDA 
             EEPROM.write(EE_OUT1_DIA_ON ,    data[6]); //OUT1 = dia DE ENCENDIDA
             EEPROM.write(EE_OUT2_HORA_ON ,   data[7]); //OUT2 = HORA DE ENCENDIDA 
             EEPROM.write(EE_OUT2_MINUTOS_ON ,data[8]); //OUT2 = MINUTOS DE ENCENDIDA 
             EEPROM.write(EE_OUT2_DIA_ON ,    data[9]); //OUT2 = MINUTOS DE ENCENDIDA
             EEPROM.write(EE_OUT3_HORA_ON ,   data[10]); //OUT3 = HORA DE ENCENDIDA 
             EEPROM.write(EE_OUT3_MINUTOS_ON ,data[11]); //OUT3 = MINUTOS DE ENCENDIDA 
             EEPROM.write(EE_OUT3_DIA_ON ,    data[12]); //OUT3 = MINUTOS DE ENCENDIDA
             EEPROM.write(EE_OUT4_HORA_ON ,   data[13]); //OUT4 = HORA DE ENCENDIDA 
             EEPROM.write(EE_OUT4_MINUTOS_ON ,data[14]); //OUT4 = MINUTOS DE ENCENDIDA 
             EEPROM.write(EE_OUT4_DIA_ON ,    data[15]); //OUT4 = MINUTOS DE ENCENDIDA
             EEPROM.write(EE_OUT5_HORA_ON ,   data[16]); //OUT5 = HORA DE ENCENDIDA 
             EEPROM.write(EE_OUT5_MINUTOS_ON ,data[17]); //OUT5 = MINUTOS DE ENCENDIDA 
             EEPROM.write(EE_OUT5_DIA_ON ,    data[18]); //OUT5 = MINUTOS DE ENCENDIDA
             EEPROM.write(EE_OUT6_HORA_ON ,   data[19]); //OUT6 = HORA DE ENCENDIDA 
             EEPROM.write(EE_OUT6_MINUTOS_ON ,data[20]); //OUT6 = MINUTOS DE ENCENDIDA 
             EEPROM.write(EE_OUT6_DIA_ON ,    data[21]); //OUT6 = MINUTOS DE ENCENDIDA
             EEPROM.write(EE_OUT7_HORA_ON ,   data[22]); //OUT7 = HORA DE ENCENDIDA 
             EEPROM.write(EE_OUT7_MINUTOS_ON ,data[23]); //OUT7 = MINUTOS DE ENCENDIDA 
             EEPROM.write(EE_OUT7_DIA_ON ,    data[24]); //OUT7 = MINUTOS DE ENCENDIDA
             EEPROM.write(EE_OUT8_HORA_ON ,   data[25]); //OUT8 = HORA DE ENCENDIDA 
             EEPROM.write(EE_OUT8_MINUTOS_ON ,data[26]); //OUT8 = MINUTOS DE ENCENDIDA 
             EEPROM.write(EE_OUT8_DIA_ON ,    data[27]); //OUT8 = MINUTOS DE ENCENDIDA

                  
             return;
             
}
void Grabar_Datos_EEPROM_OFF(void)

{             
          
             EEPROM.write(EE_SALIDAS_RELOJ_OFF,data[3]); //OUT1 = SALIDA DESACTIVA CON HORA DEL RELOJ            
             EEPROM.write(EE_OUT1_HORA_OFF ,   data[4]); //OUT1 = HORA DE APAGADA 
             EEPROM.write(EE_OUT1_MINUTOS_OFF ,data[5]); //OUT1 = MINUTOS DE APAGADA 
             EEPROM.write(EE_OUT1_DIA_OFF ,    data[6]); //OUT1 = MINUTOS DE APAGADA
             EEPROM.write(EE_OUT2_HORA_OFF ,   data[7]); //OUT2 = HORA DE APAGADA 
             EEPROM.write(EE_OUT2_MINUTOS_OFF ,data[8]); //OUT2 = MINUTOS DE APAGADA 
             EEPROM.write(EE_OUT2_DIA_OFF ,    data[9]); //OUT2 = MINUTOS DE APAGADA
             EEPROM.write(EE_OUT3_HORA_OFF ,   data[10]); //OUT3 = HORA DE APAGADA 
             EEPROM.write(EE_OUT3_MINUTOS_OFF ,data[11]); //OUT3 = MINUTOS DE APAGADA 
             EEPROM.write(EE_OUT3_DIA_OFF ,    data[12]); //OUT3 = MINUTOS DE APAGADA
             EEPROM.write(EE_OUT4_HORA_OFF ,   data[13]); //OUT4 = HORA DE APAGADA 
             EEPROM.write(EE_OUT4_MINUTOS_OFF ,data[14]); //OUT4 = MINUTOS DE APAGADA 
             EEPROM.write(EE_OUT4_DIA_OFF ,    data[15]); //OUT4 = MINUTOS DE APAGADA
             EEPROM.write(EE_OUT5_HORA_OFF ,   data[16]); //OUT5 = HORA DE APAGADA 
             EEPROM.write(EE_OUT5_MINUTOS_OFF ,data[17]); //OUT5 = MINUTOS DE APAGADA 
             EEPROM.write(EE_OUT5_DIA_OFF ,    data[18]); //OUT5 = MINUTOS DE APAGADA
             EEPROM.write(EE_OUT6_HORA_OFF ,   data[19]); //OUT6 = HORA DE APAGADA 
             EEPROM.write(EE_OUT6_MINUTOS_OFF ,data[20]); //OUT6 = MINUTOS DE APAGADA 
             EEPROM.write(EE_OUT6_DIA_OFF ,    data[21]); //OUT6 = MINUTOS DE APAGADA
             EEPROM.write(EE_OUT7_HORA_OFF ,   data[22]); //OUT7 = HORA DE APAGADA 
             EEPROM.write(EE_OUT7_MINUTOS_OFF ,data[23]); //OUT7 = MINUTOS DE APAGADA 
             EEPROM.write(EE_OUT7_DIA_OFF ,    data[24]); //OUT7 = MINUTOS DE APAGADA
             EEPROM.write(EE_OUT8_HORA_OFF ,   data[25]); //OUT8 = HORA DE APAGADA 
             EEPROM.write(EE_OUT8_MINUTOS_OFF ,data[26]); //OUT8 = MINUTOS DE APAGADA 
             EEPROM.write(EE_OUT8_DIA_OFF ,    data[27]); //OUT8 = MINUTOS DE APAGADA      
             return;
             
}

void salida_1_off(DateTime date)
{

   int Hora_out1_off = date.hour ();
   int Minutos_out1_off = date.minute();
   int weekDay_out1_off = date.dayOfTheWeek();
        if (OUT1_DIA_OFF < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT1_HORA_OFF == Hora_out1_off && OUT1_MINUTOS_OFF == Minutos_out1_off && weekDay_out1_off == OUT1_DIA_OFF)
          {
           OUT1_CONDICION_OFF = true;
          }
       } 
       if (OUT1_DIA_OFF > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_OFF
         {
         if (OUT1_HORA_OFF == Hora_out1_off && OUT1_MINUTOS_OFF == Minutos_out1_off )
         {
           OUT1_CONDICION_OFF = true;
         }     
       }
}


 void salida_2_off(DateTime date)
{

   int Hora_OUT2_OFF = date.hour ();
   int Minutos_OUT2_OFF = date.minute();
   int weekDay_OUT2_OFF = date.dayOfTheWeek();
        if (OUT2_DIA_OFF < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT2_HORA_OFF == Hora_OUT2_OFF && OUT2_MINUTOS_OFF == Minutos_OUT2_OFF && weekDay_OUT2_OFF == OUT2_DIA_OFF)
          {
           OUT2_CONDICION_OFF = true;
          }
       } 
       if (OUT2_DIA_OFF > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_OFF
         {
         if (OUT2_HORA_OFF == Hora_OUT2_OFF && OUT2_MINUTOS_OFF == Minutos_OUT2_OFF )
         {
           OUT2_CONDICION_OFF = true;
         }     
       }
}

 void salida_3_off(DateTime date)
{

   int Hora_OUT3_OFF = date.hour ();
   int Minutos_OUT3_OFF = date.minute();
   int weekDay_OUT3_OFF = date.dayOfTheWeek();
        if (OUT3_DIA_OFF < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT3_HORA_OFF == Hora_OUT3_OFF && OUT3_MINUTOS_OFF == Minutos_OUT3_OFF && weekDay_OUT3_OFF == OUT3_DIA_OFF)
          {
           OUT3_CONDICION_OFF = true;
          }
       } 
       if (OUT3_DIA_OFF > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_OFF
         {
         if (OUT3_HORA_OFF == Hora_OUT3_OFF && OUT3_MINUTOS_OFF == Minutos_OUT3_OFF )
         {
           OUT3_CONDICION_OFF = true;
         }     
       }

}

 void salida_4_off(DateTime date)
{
   int Hora_OUT4_OFF = date.hour ();
   int Minutos_OUT4_OFF = date.minute();
   int weekDay_OUT4_OFF = date.dayOfTheWeek();
        if (OUT4_DIA_OFF < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT4_HORA_OFF == Hora_OUT4_OFF && OUT4_MINUTOS_OFF == Minutos_OUT4_OFF && weekDay_OUT4_OFF == OUT4_DIA_OFF)
          {
           OUT4_CONDICION_OFF = true;
          }
       } 
       if (OUT4_DIA_OFF > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_OFF
         {
         if (OUT4_HORA_OFF == Hora_OUT4_OFF && OUT4_MINUTOS_OFF == Minutos_OUT4_OFF )
         {
           OUT4_CONDICION_OFF = true;
         }     
       }
}

 void salida_5_off(DateTime date)
{

   int Hora_OUT5_OFF = date.hour ();
   int Minutos_OUT5_OFF = date.minute();
   int weekDay_OUT5_OFF = date.dayOfTheWeek();
        if (OUT5_DIA_OFF < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT5_HORA_OFF == Hora_OUT5_OFF && OUT5_MINUTOS_OFF == Minutos_OUT5_OFF && weekDay_OUT5_OFF == OUT5_DIA_OFF)
          {
           OUT5_CONDICION_OFF = true;
          }
       } 
       if (OUT5_DIA_OFF > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_OFF
         {
         if (OUT5_HORA_OFF == Hora_OUT5_OFF && OUT5_MINUTOS_OFF == Minutos_OUT5_OFF )
         {
           OUT5_CONDICION_OFF = true;
         }     
       }
}

 void salida_6_off(DateTime date)
{
   int Hora_OUT6_OFF = date.hour ();
   int Minutos_OUT6_OFF = date.minute();
   int weekDay_OUT6_OFF = date.dayOfTheWeek();
        if (OUT6_DIA_OFF < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT6_HORA_OFF == Hora_OUT6_OFF && OUT6_MINUTOS_OFF == Minutos_OUT6_OFF && weekDay_OUT6_OFF == OUT6_DIA_OFF)
          {
           OUT6_CONDICION_OFF = true;
          }
       } 
       if (OUT6_DIA_OFF > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_OFF
         {
         if (OUT6_HORA_OFF == Hora_OUT6_OFF && OUT6_MINUTOS_OFF == Minutos_OUT6_OFF )
         {
           OUT6_CONDICION_OFF = true;
         }     
       }
}

 void salida_7_off(DateTime date)
{
   int Hora_OUT7_OFF = date.hour ();
   int Minutos_OUT7_OFF = date.minute();
   int weekDay_OUT7_OFF = date.dayOfTheWeek();
        if (OUT7_DIA_OFF < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT7_HORA_OFF == Hora_OUT7_OFF && OUT7_MINUTOS_OFF == Minutos_OUT7_OFF && weekDay_OUT7_OFF == OUT7_DIA_OFF)
          {
           OUT7_CONDICION_OFF = true;
          }
       } 
       if (OUT7_DIA_OFF > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_OFF
         {
         if (OUT7_HORA_OFF == Hora_OUT7_OFF && OUT7_MINUTOS_OFF == Minutos_OUT7_OFF )
         {
           OUT7_CONDICION_OFF = true;
         }     
       }
}

 void salida_8_off(DateTime date)
{
   int Hora_OUT8_OFF = date.hour ();
   int Minutos_OUT8_OFF = date.minute();
   int weekDay_OUT8_OFF = date.dayOfTheWeek();
        if (OUT8_DIA_OFF < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT8_HORA_OFF == Hora_OUT8_OFF && OUT8_MINUTOS_OFF == Minutos_OUT8_OFF && weekDay_OUT8_OFF == OUT8_DIA_OFF)
          {
           OUT8_CONDICION_OFF = true;
          }
       } 
       if (OUT8_DIA_OFF > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_OFF
         {
         if (OUT8_HORA_OFF == Hora_OUT8_OFF && OUT8_MINUTOS_OFF == Minutos_OUT8_OFF )
         {
           OUT8_CONDICION_OFF = true;
         }     
       }

}


 void salida_1(DateTime date)
{

   int Hora_OUT1_ON = date.hour();
   int Minutos_OUT1_ON = date.minute();
   int weekDay_OUT1_ON = date.dayOfTheWeek();
        if (OUT1_DIA_ON < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         // Serial.println("Es domingo");
          
         if (OUT1_HORA_ON == Hora_OUT1_ON && OUT1_MINUTOS_ON == Minutos_OUT1_ON && weekDay_OUT1_ON == OUT1_DIA_ON)
          {
           // Serial.println("Es igual a la hora");
           OUT1_CONDICION_ON = true;
          }
       } 
       if (OUT1_DIA_ON > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_ON
         {
         if (OUT1_HORA_ON == Hora_OUT1_ON && OUT1_MINUTOS_ON == Minutos_OUT1_ON )
         {
           OUT1_CONDICION_ON = true;
         }     
       }
}


 void salida_2(DateTime date)
{

   int Hora_OUT2_ON = date.hour ();
   int Minutos_OUT2_ON = date.minute();
   int weekDay_OUT2_ON = date.dayOfTheWeek();
        if (OUT2_DIA_ON < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT2_HORA_ON == Hora_OUT2_ON && OUT2_MINUTOS_ON == Minutos_OUT2_ON && weekDay_OUT2_ON == OUT2_DIA_ON)
          {
           OUT2_CONDICION_ON = true;
          }
       } 
       if (OUT2_DIA_ON > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_ON
         {
         if (OUT2_HORA_ON == Hora_OUT2_ON && OUT2_MINUTOS_ON == Minutos_OUT2_ON )
         {
           OUT2_CONDICION_ON = true;
         }     
       }
}

 void salida_3(DateTime date)
{

   int Hora_OUT3_ON = date.hour ();
   int Minutos_OUT3_ON = date.minute();
   int weekDay_OUT3_ON = date.dayOfTheWeek();
        if (OUT3_DIA_ON < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT3_HORA_ON == Hora_OUT3_ON && OUT3_MINUTOS_ON == Minutos_OUT3_ON && weekDay_OUT3_ON == OUT3_DIA_ON)
          {
           OUT3_CONDICION_ON = true;
          }
       } 
       if (OUT3_DIA_ON > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_ON
         {
         if (OUT3_HORA_ON == Hora_OUT3_ON && OUT3_MINUTOS_ON == Minutos_OUT3_ON )
         {
           OUT3_CONDICION_ON = true;
         }     
       }
}

 void salida_4(DateTime date)
{
   int Hora_OUT4_ON = date.hour ();
   int Minutos_OUT4_ON = date.minute();
   int weekDay_OUT4_ON = date.dayOfTheWeek();
        if (OUT4_DIA_ON < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT4_HORA_ON == Hora_OUT4_ON && OUT4_MINUTOS_ON == Minutos_OUT4_ON && weekDay_OUT4_ON == OUT4_DIA_ON)
          {
           OUT4_CONDICION_ON = true;
          }
       } 
       if (OUT4_DIA_ON > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_ON
         {
         if (OUT4_HORA_ON == Hora_OUT4_ON && OUT4_MINUTOS_ON == Minutos_OUT4_ON )
         {
           OUT4_CONDICION_ON = true;
         }     
       }
}

 void salida_5(DateTime date)
{

   int Hora_OUT5_ON = date.hour ();
   int Minutos_OUT5_ON = date.minute();
   int weekDay_OUT5_ON = date.dayOfTheWeek();
        if (OUT5_DIA_ON < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT5_HORA_ON == Hora_OUT5_ON && OUT5_MINUTOS_ON == Minutos_OUT5_ON && weekDay_OUT5_ON == OUT5_DIA_ON)
          {
           OUT5_CONDICION_ON = true;
          }
       } 
       if (OUT5_DIA_ON > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_ON
         {
         if (OUT5_HORA_ON == Hora_OUT5_ON && OUT5_MINUTOS_ON == Minutos_OUT5_ON )
         {
           OUT5_CONDICION_ON = true;
         }     
       }}

 void salida_6(DateTime date)
{
   int Hora_OUT6_ON = date.hour ();
   int Minutos_OUT6_ON = date.minute();
   int weekDay_OUT6_ON = date.dayOfTheWeek();
        if (OUT6_DIA_ON < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT6_HORA_ON == Hora_OUT6_ON && OUT6_MINUTOS_ON == Minutos_OUT6_ON && weekDay_OUT6_ON == OUT6_DIA_ON)
          {
           OUT6_CONDICION_ON = true;
          }
       } 
       if (OUT6_DIA_ON > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_ON
         {
         if (OUT6_HORA_ON == Hora_OUT6_ON && OUT6_MINUTOS_ON == Minutos_OUT6_ON )
         {
           OUT6_CONDICION_ON = true;
         }     
       }

}

 void salida_7(DateTime date)
{

   int Hora_OUT7_ON = date.hour ();
   int Minutos_OUT7_ON = date.minute();
   int weekDay_OUT7_ON = date.dayOfTheWeek();
        if (OUT7_DIA_ON < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT7_HORA_ON == Hora_OUT7_ON && OUT7_MINUTOS_ON == Minutos_OUT7_ON && weekDay_OUT7_ON == OUT7_DIA_ON)
          {
           OUT7_CONDICION_ON = true;
          }
       } 
       if (OUT7_DIA_ON > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_ON
         {
         if (OUT7_HORA_ON == Hora_OUT7_ON && OUT7_MINUTOS_ON == Minutos_OUT7_ON )
         {
           OUT7_CONDICION_ON = true;
         }     
       }
}

 void salida_8(DateTime date)
{
   int Hora_OUT8_ON = date.hour ();
   int Minutos_OUT8_ON = date.minute();
   int weekDay_OUT8_ON = date.dayOfTheWeek();
   
        if (OUT8_DIA_ON < 7) // SI EL DIA ESTA DENTRO DE DOMINGO = 0 A SABADO = 6 ENTRA AQUI
       {
         if (OUT8_HORA_ON == Hora_OUT8_ON && OUT8_MINUTOS_ON == Minutos_OUT8_ON && weekDay_OUT8_ON == OUT8_DIA_ON)
          {
           OUT8_CONDICION_ON = true;
          }
       } 
       if (OUT8_DIA_ON > 6) // SI ESTA SELECCIONADO TODOS LOS DIAS, ENTONCES ENTRA AQUI Y NO COMPARA LA VARIABLE WEEKDAY_OUT_ON
         {
         if (OUT8_HORA_ON == Hora_OUT8_ON && OUT8_MINUTOS_ON == Minutos_OUT8_ON )
         {
           OUT8_CONDICION_ON = true;
         }     
       }
}

static word homePage() 
{

  bfill = ether.tcpOffset();

  if (GET_ENTRADAS_DIGITALES == 1) 
  {
    GET_ENTRADAS_DIGITALES =0;
    bool Estado_IN1 = digitalRead(IN1);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Entrada Digital 1\": \"$D\"}"
    ),
      Estado_IN1);
    return bfill.position();
  }


  else if (GET_ENTRADAS_DIGITALES == 2) 
  {
    GET_ENTRADAS_DIGITALES =0;
    bool Estado_IN2 = digitalRead(IN2);
   // bool Estado_IN2 = 0;
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Entrada Digital 2\": \"$D\"}"
    ),
      Estado_IN2);
    return bfill.position();
  }

  else if (  GET_ENTRADAS_DIGITALES == 3) 
  {
     GET_ENTRADAS_DIGITALES =0;
    bool Estado_IN3 = digitalRead(IN3);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Entrada Digital 3\": \"$D\"}"
    ),
      Estado_IN3);
    return bfill.position();
  }
 
  else if (GET_ENTRADAS_DIGITALES == 4) 
  {
    GET_ENTRADAS_DIGITALES =0;
    bool Estado_IN4 = digitalRead(IN4);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Entrada Digital 4\": \"$D\"}"
    ),
      Estado_IN4);
    return bfill.position();
  }

  else if (GET_ENTRADAS_DIGITALES == 5) 
  {
    GET_ENTRADAS_DIGITALES =0;
    int Valor_INA1 = analogRead(A7);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Entrada Analogica 1\": \"$D\"}"
    ),
      Valor_INA1);
    return bfill.position();
  }

  
  else if (GET_ENTRADAS_DIGITALES == 6) 
  {
    GET_ENTRADAS_DIGITALES =0;
    int Valor_INA2 = analogRead(A6);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Entrada Analogica 2\": \"$D\"}"
    ),
      Valor_INA2);
    return bfill.position();
  }
 else if (POST_SALIDAS_DIGITALES== 1) 
  {
    digitalWrite(OUT1,HIGH);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 1\": \"$S\"}"
    ),
      "ON");
    return bfill.position();
  }

 else if (POST_SALIDAS_DIGITALES== 2) 
  {
     
    digitalWrite(OUT2,HIGH);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 2\": \"$S\"}"
    ),
      "ON");
    return bfill.position();
  }

 else if (POST_SALIDAS_DIGITALES== 3) 
  {
  
    digitalWrite(OUT3,HIGH);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 3\": \"$S\"}"
    ),
      "ON");
    return bfill.position();
  }


 else if (POST_SALIDAS_DIGITALES== 4) 
  {
    
    digitalWrite(OUT4,HIGH);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 4\": \"$S\"}"
    ),
      "ON");
    return bfill.position();
  }


 else if (POST_SALIDAS_DIGITALES== 5) 
  {
     
    digitalWrite(OUT5,LOW);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 5\": \"$S\"}"
    ),
      "ON");
    return bfill.position();
  }



 else if (POST_SALIDAS_DIGITALES== 6) 
  {
     //Serial.println("salida 6");
    digitalWrite(OUT6,LOW);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 6\": \"$S\"}"
    ),
      "ON");
    return bfill.position();
  }


 else if (POST_SALIDAS_DIGITALES== 7) 
  {
 
    digitalWrite(OUT7,LOW);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 7\": \"$S\"}"
    ),
      "ON");
    return bfill.position();
  }

 else if (POST_SALIDAS_DIGITALES== 8) 
  {

    digitalWrite(OUT8,LOW);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 8\": \"$S\"}"
    ),
      "ON");
    return bfill.position();
  }
  

else if (POST_SALIDAS_DIGITALES== 9) 
  {
    
    digitalWrite(OUT1,LOW);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 1\": \"$S\"}"
    ),
      "OFF");
    return bfill.position();
  }

 else if (POST_SALIDAS_DIGITALES== 10) 
  {
 
    digitalWrite(OUT2,LOW);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 2\": \"$S\"}"
    ),
      "OFF");
    return bfill.position();
  }

 else if (POST_SALIDAS_DIGITALES== 11) 
  {

    digitalWrite(OUT3,LOW);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 3\": \"$S\"}"
    ),
      "OFF");
    return bfill.position();
  }


 else if (POST_SALIDAS_DIGITALES== 12) 
  {

    digitalWrite(OUT4,LOW);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 4\": \"$S\"}"
    ),
      "OFF");
    return bfill.position();
  }


 else if (POST_SALIDAS_DIGITALES== 13) 
  {
     
    digitalWrite(OUT5,HIGH);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 5\": \"$S\"}"
    ),
      "OFF");
    return bfill.position();
  }

 else if (POST_SALIDAS_DIGITALES== 14) 
  {

    digitalWrite(OUT6,HIGH);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 6\": \"$S\"}"
    ),
      "OFF");
    return bfill.position();
  }

 else if (POST_SALIDAS_DIGITALES== 15) 
  {

    digitalWrite(OUT7,HIGH);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 7\": \"$S\"}"
    ),
      "OFF");
    return bfill.position();
  }

 else if (POST_SALIDAS_DIGITALES== 16) 
  {

    digitalWrite(OUT8,HIGH);
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"Salida Digital 8\": \"$S\"}"
    ),
      "OFF");
    return bfill.position();
  }


  
    else if (  GET_ENTRADAS_DIGITALES == 0) 
  {
 
    bfill.emit_p(PSTR(
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "\r\n" 
    "{\"TRAMA JSON\": \"$S\"}"
    ),
      "Error");
    return bfill.position();
  }

}
