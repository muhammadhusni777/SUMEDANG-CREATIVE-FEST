//#include <SoftwareSerial.h>
//SoftwareSerial BTSerial(2, 3);

int nadado1 = 2;
int nadado2 = 3;
int nadare1 = 4;
int nadare2 = 5;
int nadami1 = 6;
int nadami2 = 7;
int nadapa1 = 8;
int nadapa2 = 9;
int nadaso1 = 10;
int nadaso2 = 11;
int nadala1 = A0;
int nadala2 = A1;
int nadasi1 = A2;
int nadasi2 = A3;
int nadadoo1 = A4;
int nadadoo2 = A5;
char Tampung;

void setup()
{

  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  //  BTSerial.begin(9600);
  pinMode(nadado1, OUTPUT);
  pinMode(nadado2, OUTPUT);
  pinMode(nadare1, OUTPUT);
  pinMode(nadare2, OUTPUT);
  pinMode(nadami1, OUTPUT);
  pinMode(nadami2, OUTPUT);
  pinMode(nadapa1, OUTPUT);
  pinMode(nadapa2, OUTPUT);
  pinMode(nadaso1, OUTPUT);
  pinMode(nadaso2, OUTPUT);
  pinMode(nadala1, OUTPUT);
  pinMode(nadala2, OUTPUT);
  pinMode(nadasi1, OUTPUT);
  pinMode(nadasi2, OUTPUT);
  pinMode(nadadoo1, OUTPUT);
  pinMode(nadadoo2, OUTPUT);

}

void loop()
{
  if (Serial.available())
  {

    //    Tampung = BTSerial.read();
    Tampung = Serial.read();
    Serial.write('Tampung');
    Serial.println("Tampung");
    if (Tampung == '1')
    {
      Serial.println("Do");
      DO(1);
    }
    if (Tampung == '2')
    {
      Serial.println("Re");
      RE(1);
    }
    if (Tampung == '3')
    {
      Serial.println("Mi");
      MI(1);
    }
    if (Tampung == '4')
    {
      Serial.println("Pa");
      FA(1);
    }
    if (Tampung == '5')
    {
      Serial.println("Sol");
      SOL(1);
    }
    if (Tampung == '6')
    {
      Serial.println("La");
      LA(1);
    }
    if (Tampung == '7')
    {
      Serial.println("Si");
      SI(1);
    }
    if (Tampung == '8')
    {
      Serial.println("Doo");
      DOO(1);
    }

    if (Tampung == 'f')
    {
      Serial.println("Balonku");
      Balonku();
    }
    if (Tampung == 'e')
    {
      Serial.println("Sikancil");
      Sikancil();
    }
    if (Tampung == 'a')
    {
      Serial.println("Kebunku");
      Kebunku();
    }
    if (Tampung == 'b')
    {
      Serial.println("Kasih Ibu");
      KasihIbu();
    }
    if (Tampung == 'c')
    {
      Serial.println("Dua Mata Saya");
      DuaMataSaya();
    }
    if (Tampung == 'd')
    {
      Serial.println("Ambilkan Bulan Bu");
      AmbilkanBulanBu();
    }
    if (Tampung == 'g')
    {
      Serial.println("Kartini");
      Kartini();
    }


  }
}

void KasihIbu()
{
  MI(2);
  RE(1);
  MI(1);
  DO(2);
  DIAM(1);

  DO(1);
  DOO(2);
  LA(1);
  DOO(1);
  SOL(2);
  DIAM(2);

  LA(2);
  SOL(1);
  FA(1);
  MI(2);
  DO(1);
  RE(1);
  MI(2);
  SOL(1);
  MI(1);
  RE(2);
  DIAM(2);

  MI(2);
  RE(1);
  MI(1);
  DO(2);
  DIAM(1);

  DO(1);
  DOO(2);
  LA(1);
  DOO(1);
  SOL(2);
  DIAM(2);

  LA(2);
  SOL(1);
  FA(1);
  MI(2);
  DO(1);
  RE(1);
  MI(2);
  RE(2);
  DO(2);
  DIAM(2);
}


void DuaMataSaya()
{
  SOL(1);
  MI(2);
  MI(2);
  SOL(2);
  DIAM(1);

  SOL(1);
  DOO(1);
  SOL(1);
  FA(1);
  MI(1);
  RE(2);
  DIAM(1);

  FA(1);
  RE(2);
  RE(2);
  FA(2);
  LA(2);
  SOL(1);
  DO(1);
  MI(1);
  RE(1);
  DO(2);
  DIAM(1);

  SOL(1);
  MI(2);
  MI(2);
  SOL(2);
  DIAM(1);

  SOL(1);
  DOO(1);
  SOL(1);
  FA(1);
  MI(1);
  RE(2);
  DIAM(1);

  FA(1);
  RE(2);
  RE(2);
  FA(2);
  LA(2);
  SOL(1);
  DO(1);
  MI(1);
  RE(1);
  DO(2);
  DIAM(2);
}


void Sikancil()
{
  DO(2);
  MI(2);
  SOL(4);
  DOO(4);
  SOL(2);
  DIAM(2);

  MI(2);
  FA(2);
  SOL(4);
  FA(2);
  MI(2);
  RE(2);
  DIAM(2);

  LA(4);
  SOL(4);
  LA(2);
  SI(2);
  DOO(2);
  DIAM(2);

  MI(2);
  FA(2);
  SOL(2);
  FA(2);
  MI(2);
  RE(2);
  DO(2);
  DIAM(2);
}

void AmbilkanBulanBu()
{
  MI(1);
  RE(1);
  DO(1);
  RE(1);
  MI(3);
  DIAM(1);

  MI(1);
  RE(1);
  DO(1);
  MI(1);
  FA(3);
  DIAM(1);

  FA(1);
  MI(1);
  RE(1);
  MI(1);
  SOL(3);
  FA(1);
  MI(1);
  RE(1);
  DO(3);
  DIAM(4);

  MI(1);
  RE(1);
  DO(2);
  DIAM(1);

  DO(1);
  DOO(3);
  SI(3);
  LA(4);
  FA(1);
  MI(1);
  RE(2);
  DIAM(1);

  RE(1);
  SI(3);
  LA(3);
  SOL(3);
  MI(1);
  RE(1);
  DO(1);
  RE(1);
  MI(3);
  DIAM(1);

  MI(1);
  RE(1);
  DO(1);
  MI(1);
  FA(3);
  DIAM(1);

  FA(1);
  MI(1);
  RE(1);
  MI(1);
  SOL(3);
  FA(1);
  MI(1);
  RE(1);
  DO(3);
  DIAM(4);
}

void Kebunku()
{
  SOL(4); //Lihat Kebunku
  MI(2);
  SOL(2);
  DOO(4);
  DIAM(2);

  SOL(2); //PENUH
  MI(2);
  SOL(2); //DENGAN
  FA(2);
  MI(2); //BUNGA
  RE(4);
  DIAM(2);

  FA(4); //ADA
  RE(2); //YANG
  FA(2); //MERAH
  SI(4);
  DIAM(2);

  LA(2); //DAN A
  SOL(2);
  LA(2); //DA YANG
  SOL(2);
  FA(2); //PUTIH
  MI(4);
  DIAM(2);

  SOL(4); //SETIAP
  MI(2);
  SOL(2); //HARI
  DOO(4);
  DIAM(2);

  SOL(2); //KU
  MI(2); //SIRAM
  SOL(2);
  FA(2); //SEMUA
  MI(2);
  RE(4);
  DIAM(2);

  FA(4); //MAWAR
  RE(2); //MELATI
  FA(2);
  SI(4);
  DIAM(2);

  LA(2); //SEMUANYA
  SOL(4);
  LA(2);
  SI(2); //INDAH
  DOO(4);
  DIAM(2);
}

void Kartini()
{
  RE(3); //IBU
  MI(1);
  FA(2); //KITA
  SOL(2);
  LA(3); //KARTINI
  FA(1);
  RE(2);
  DIAM(2);

  SI(3); //PUTRI
  RE(1);
  DO(2); //SEJATI
  SI(2);
  LA(6);
  DIAM(2);

  SOL(3); //PUTRI
  SI(1);
  LA(2); //INDONESIA
  SOL(2);
  FA(2);
  RE(4);
  DIAM(2);

  MI(3); //HARUM
  SOL(1);
  FA(2); //NAMANYA
  MI(2);
  RE(6);
  DIAM(2);

  RE(3); //IBU
  MI(1);
  FA(2); //KITA
  SOL(2);
  LA(3); //KARTINI
  FA(1);
  RE(2);
  DIAM(2);

  SI(3); //PUTRI
  RE(1);
  DO(2); //SEJATI
  SI(2);
  LA(6);
  DIAM(2);

  SOL(3); //PUTRI
  SI(1);
  LA(2); //INDONESIA
  SOL(2);
  FA(2);
  RE(4);
  DIAM(2);

  MI(3); //HARUM
  SOL(1);
  FA(2); //NAMANYA
  MI(2);
  RE(6);
  DIAM(2);

  SOL(3); //WAHAI
  FA(1);
  SOL(2); //IBU
  SI(2);
  LA(1); //KITA
  SI(1);
  LA(1); //KARTINI
  FA(1);
  RE(2);
  DIAM(1);

  FA(2); //PUTRI
  MI(2);
  FA(3); //YANG
  SOL(2); //MULIA
  LA(2);
  FA(4);
  DIAM(2);


  SOL(3); //WAHAI
  FA(1);
  SOL(2); //IBU
  SI(2);
  LA(1); //KITA
  SI(1);
  LA(1); //KARTINI
  FA(1);
  RE(2);
  DIAM(1);

  FA(2); //PUTRI
  MI(2);
  SOL(2);
  DO(2);
  MI(2);
  RE(6);
  DIAM(2);

}



void Balonku()
{
  MI (1);  //Balonku
  FA (1);
  SOL (2);
  DOO (2);  //Ada
  SOL (2);
  MI (2);  //Lima
  SOL (4);
  DIAM (2);

  RE (1);
  MI (1);
  FA (2);
  RE (2);
  SOL (2);
  FA (2);
  MI (4);
  DIAM (2);

  DO (1);
  DO (1);
  LA (2);
  LA (2);
  SI (2);
  DOO (2);
  SOL (4);
  DIAM (2);

  MI (1);
  FA (1);
  SOL (2);
  FA (2);
  MI (2);
  RE (2);
  DO (4);
  DIAM (2);

  MI (1);  //Meletus
  FA (1);
  SOL (2);
  DOO (2);  //Balon
  SOL (2);
  MI (2);  //Hijau
  SOL (2);
  DIAM (1);

  DOO (1);  //DOR !!
  DIAM (2);

  RE (1);
  MI (1);
  FA (2);
  RE (2);
  SOL (2);
  FA (2);
  MI (4);
  DIAM (2);

  DO (1);
  DO (1);
  LA (2);
  LA (2);
  SI (2);
  DOO (2);
  SOL (4);
  DIAM (2);

  MI (1);
  FA (1);
  SOL (2);
  FA (2);
  MI (2);
  RE (2);
  DO (4);
  DIAM (2);
}

void DO(float x)
{
  int a;
  for (a = 0; a < x * 4; a++) {
    digitalWrite(nadado1, 9);
    digitalWrite(nadado2, LOW);
    delay(50);
    digitalWrite(nadado1, LOW);
    digitalWrite(nadado2, 9);
    delay(50);
    digitalWrite(nadado1, LOW);
    digitalWrite(nadado2, LOW);
  }
}

void RE(float x)
{
  int a;
  for (a = 0; a < x * 4; a++) {
    digitalWrite(nadare1, HIGH);
    digitalWrite(nadare2, LOW);
    delay(50);
    digitalWrite(nadare1, LOW);
    digitalWrite(nadare2, HIGH);
    delay(50);
    digitalWrite(nadare1, LOW);
    digitalWrite(nadare2, LOW);
  }
}

void MI(float x)
{
  int a;
  for (a = 0; a < x * 4; a++) {
    digitalWrite(nadami1, 9);
    digitalWrite(nadami2, LOW);
    delay(50);
    digitalWrite(nadami1, LOW);
    digitalWrite(nadami2, 9);
    delay(50);
    digitalWrite(nadami1, LOW);
    digitalWrite(nadami2, LOW);
  }
}

void FA(float x)
{
  int a;
  for (a = 0; a < x * 4; a++) {
    digitalWrite(nadapa1, 9);
    digitalWrite(nadapa2, LOW);
    delay(50);
    digitalWrite(nadapa1, LOW);
    digitalWrite(nadapa2, 9);
    delay(50);
    digitalWrite(nadapa1, LOW);
    digitalWrite(nadapa2, LOW);
  }
}

void SOL(float x)
{
  int a;
  for (a = 0; a < x * 4; a++) {
    digitalWrite(nadaso1, 9);
    digitalWrite(nadaso2, LOW);
    delay(50);
    digitalWrite(nadaso1, LOW);
    digitalWrite(nadaso2, 9);
    delay(50);
    digitalWrite(nadaso1, LOW);
    digitalWrite(nadaso2, LOW);
  }
}

void LA(float x)
{
  int a;
  for (a = 0; a < x * 4; a++) {
    digitalWrite(nadala1, 9);
    digitalWrite(nadala2, LOW);
    delay(50);
    digitalWrite(nadala1, LOW);
    digitalWrite(nadala2, 9);
    delay(50);
    digitalWrite(nadala1, LOW);
    digitalWrite(nadala2, LOW);
  }
}

void SI(float x)
{
  int a;
  for (a = 0; a < x * 4; a++) {
    digitalWrite(nadasi1, 9);
    digitalWrite(nadasi2, LOW);
    delay(50);
    digitalWrite(nadasi1, LOW);
    digitalWrite(nadasi2, 9);
    delay(50);
    digitalWrite(nadasi1, LOW);
    digitalWrite(nadasi2, LOW);
  }
}

void DOO(float x)
{
  int a;
  for (a = 0; a < x * 4; a++) {
    digitalWrite(nadadoo1, 9);
    digitalWrite(nadadoo2, LOW);
    delay(50);
    digitalWrite(nadadoo1, LOW);
    digitalWrite(nadadoo2, 9);
    delay(50);
    digitalWrite(nadadoo1, LOW);
    digitalWrite(nadadoo2, LOW);
  }
}

void DIAM(int x)
{
  int a;
  for (a = 0; a < x * 4; a++) {
    delay(100);
  }
}
