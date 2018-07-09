

    /*
     * Este codigo exemplifica o uso de duas placas modulos com PCF8574 que recebem via BUS I2C
     * de uma placa Arduino UNO, sinais que ativam determinadas saidas que por sua vez ativam LEDs.
     * 
     * 
     * Note que entre a saida dos modulos e os LEDs, existe uma interface de transistores
     * já que o modulos I2C não tem suficiente corrente para acender um LED.
     * 
     * Eng.Carlos kwiek
     * contato@carloskwiek.com.br
     */
    
    #include <Wire.h>
    
    #define expansor1 0x27 // define endereco da placa I2C 1
    #define expansor2 0x27 //  "        "      "   "    "  "
    #define expansor3 0x38 // define endereco da placa I2C 2
    #define expansor4 0x38 //  "        "      "   "    "  "
    
    unsigned long lastMillis; // Armazena contagem de tempo
    unsigned long lastMillis1;//   "         "     "    "

    
    void setup()
    {
      Wire.begin(); // Inicia a biblioteca Wire
     
      lastMillis = millis(); // Iguala ultima contagem a contagem atual
      lastMillis1 = millis();//   "      "      "      "    "       "
    }
    
    void loop()
    {
      tempo(); // Função em loop
    }
      
      void comunica(byte endereco, byte digito)
      {
        Wire.beginTransmission(endereco);
        Wire.write(digito);
        Wire.endTransmission();
      }
      
      void tempo() {
      
        if ((millis() - lastMillis) >= 2000) {
         comunica(expansor1, B00000001);
        }
        if ((millis() - lastMillis) >= 2400){
         comunica(expansor2, B00000011);
        }
         if ((millis() - lastMillis) >= 2600){
         comunica(expansor3, B00000111);
         }
         if ((millis() - lastMillis) >= 2800){
         comunica(expansor4, B00001111);
         lastMillis = millis();
        }
        
        {
        if((millis() - lastMillis1) >= 2000){
         comunica(expansor1, B00000000);
         comunica(expansor2, B00000000);
         comunica(expansor3, B00000000);
         comunica(expansor4, B00000000);
         lastMillis1 = millis();
        
         }
        }
      }
      
      
      
      

