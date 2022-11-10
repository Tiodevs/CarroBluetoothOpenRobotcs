// Importa a biblioteca que nos permite usar o OpenRobotics
#include <darwin.h>

// Variaveis
int RespostaDoBluetooth; // Vai armazenas os sinais que vem do Bluetooth

// Preparação hardware
// Conecar a led vermelha no D3
// Conecar a led amarela no D2
// Conecar a sirene no D1
// Conecar motor da direira (olhando de frente pro robô) no M2
// Conecar motor da esquerda (olhando de frente pro robô) no M1

// Preparação do software 
// Você precisa baixar o APK no celular chamado PlayGO 5.0 você pode achalo no site
// https://www.openrobotics.com.br/areadedownloads

// O void setup inicia todos os componentes
void setup() {
 AtivarBluetooth(); // Começa a comunicação entre o aplicativo e o CPU
 AtivarMotores();   // Inicia a comunicação entre o motor das rodas e o CPU
 SireneNaPorta(D1); // Inicia a comunicação entre a sirene e o CPU
}
void loop() {
 if (BluetoothEstaRecebendo() == Sim) // Valida se está tudo certo com a cominicação
 {
   RespostaDoBluetooth = ReceberNumeroPeloBluetooth(); // Armazena a resposta do Bluetooth na variavel
   if (RespostaDoBluetooth == 1) // se apertar o botão 1 anda para frente
   {
    MotorM1(Re);
    MotorM2(Frente);
   }
   if (RespostaDoBluetooth == 3) // se apertar o botão 3 anda para tras
   {
    MotorM1(Frente);
    MotorM2(Re);
   }
   if (RespostaDoBluetooth == 2) // se apertar o botão 2 Desliga os motores
   {
    MotorM1(Parar);
    MotorM2(Parar);
   }
   if (RespostaDoBluetooth == 4) // se apertar o botão 4 toca sirene
   {
    LigarSirene(D1);
    EsperarSegundos(2);
    DesligarSirene(D1);
    EsperarSegundos(2);
   }
 }
}
