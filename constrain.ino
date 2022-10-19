

#define x_paso 2    // Define el Pin de STEP para Motor de eje X
#define x_dire 5    // Define el Pin de DIR  para Motor de eje X
#define x_habi 8    // Define el Pin de ENABLE  para Motor de eje X
#define y_paso 3
#define y_dire 6
#define y_habi 8

bool bandera = true;


int macetax1 = -10;  int macetay1 = -10;
int macetax2 = 0;    int macetay2 = -10;
int macetax3 = 10;   int macetay3 = -10;

int macetax4 = -10; int macetay4 = 0;
int macetax5 = 0;   int macetay5 = 0;
int macetax6 = 10;  int macetay6 = 0;

int macetax7 = -10; int macetay7 = 10;
int macetax8 = 0;   int macetay8 = 10;
int macetax9 = 10;  int macetay9 = 10;

int cordenadax = 0 ; int cordenaday = 0;

int posicionx = 0; int posiciony = 0;

int distanciax = 0; int distanciay = 0;

char opc ;

int retardo = 600;   // Menor numero el giro es mas rapido
float tiempox = 0;
float tiempoy = 0;

void setup() {

  Serial.begin(9600);
  Serial.setTimeout(10000);

  pinMode(x_paso, OUTPUT); pinMode(x_dire, OUTPUT); pinMode(x_habi, OUTPUT);
  pinMode(y_paso, OUTPUT); pinMode(y_dire, OUTPUT); pinMode(y_habi, OUTPUT);

  Serial.println( " MENU DE OPCIONES ");
  Serial.println( " seleccione la posicion a dirigirse ");
  Serial.println( " maceta 1 ");
  Serial.println( " maceta 2 " );
  Serial.println( " maceta 3 " );
  Serial.println( " maceta 4 " );
  Serial.println( " maceta 5 " );
  Serial.println( " maceta 6 " );
  Serial.println( " maceta 7" );
  Serial.println( " maceta 8" );
  Serial.println( " maceta 9" );
  Serial.println( "A posicion a la que desea ir cordenada x  , y :" );
  Serial.println( "B regar " );

}

void loop() {

  while (Serial.available())
  {

    opc = Serial.read();
    delay(10);

    if ( opc == '1')
    {
      distanciax = macetax1 - posicionx;
      distanciay = macetay1 - posiciony;
      posicionx = macetax1;
      posiciony = macetay1;
      direccion();
      regar();
    }

    if ( opc == '2')
    {
      distanciax = macetax2 - posicionx;
      distanciay = macetay2 - posiciony;
      posicionx = macetax2;
      posiciony = macetay2;
      direccion();
      regar();
    }

    if ( opc == '3')
    {
      distanciax = macetax3 - posicionx;
      distanciay = macetay3 - posiciony;
      posicionx = macetax3;
      posiciony = macetay3;
      direccion();
      regar();
    }

    if (opc == '4')
    {
      distanciax = macetax4 - posicionx;
      distanciay = macetay4 - posiciony;
      posicionx = macetax4;
      posiciony = macetay4;
      direccion();
      regar();
    }

    if ( opc == '5')
    {
      distanciax = macetax5 - posicionx;
      distanciay = macetay5 - posiciony;
      posicionx = macetax5;
      posiciony = macetay5;
      direccion();
      regar();
    }
    if ( opc == '6')
    {
      distanciax = macetax6 - posicionx;
      distanciay = macetay6 - posiciony;
      posicionx = macetax6;
      posiciony = macetay6;
      direccion();
      regar();
    }

    if ( opc == '7')
    {
      distanciax = macetax7 - posicionx;
      distanciay = macetay7 - posiciony;
      posicionx = macetax7;
      posiciony = macetay7;
      direccion();
      regar();
    }

    if (opc == '8')
    {
      distanciax = macetax8 - posicionx;
      distanciay = macetay8 - posiciony;
      posicionx = macetax8;
      posiciony = macetay8;
      direccion();
      regar();
    }

    if ( opc == '9')
    {
      distanciax = macetax9 - posicionx;
      distanciay = macetay9 - posiciony;
      posicionx = macetax9;
      posiciony = macetay9;
      direccion();
      regar();
    }
    if ( opc == 'A')
    {
      Serial.println("ingresa un valor de x");
      cordenadax = Serial.parseInt();
      cordenadax = constrain(cordenadax, -10, 10);
      Serial.println(cordenadax);
      Serial.flush();

      Serial.println("ingresa un valor de y");
      //delay(4000);
      cordenaday = Serial.parseInt();
      cordenaday = constrain(cordenaday, -10, 10);
      Serial.println(cordenaday);
      Serial.flush();

      distanciax = cordenadax - posicionx;
      distanciay = cordenaday - posiciony;
      posicionx =  cordenadax;
      posiciony =  cordenaday;
      direccion();
      regar(); 
     }

     if ( opc == 'B')
      {
        regar();
      }
    }
  }


void impresion() {
  Serial.print(" distancia x = ");
  Serial.println(distanciax);
  Serial.print(" distancia y = ");
  Serial.println(distanciay);
  Serial.print("tiempo x = ");
  Serial.println(tiempox);
  Serial.print("tiempo y = ");
  Serial.println(tiempoy);

  Serial.println( " MENU DE OPCIONES ");
  Serial.println( " seleccione la posicion a dirigirse ");
  Serial.println( " maceta 1 ");
  Serial.println( " maceta 2 " );
  Serial.println( " maceta 3 " );
  Serial.println( " maceta 4 " );
  Serial.println( " maceta 5 " );
  Serial.println( " maceta 6 " );
  Serial.println( " maceta 7" );
  Serial.println( " maceta 8" );
  Serial.println( " maceta 9" );
  Serial.println( "A posicion a la que desea ir cordenada x  , y :" );
  Serial.println( "B regar " );
}

void direccion() {
  if (distanciax >= 0) {
    tiempox = distanciax / .004;
    giro_positivo_x(x_paso, x_dire, x_habi);
  }
  if (distanciax < 0 ) {
    distanciax = -(distanciax);
    tiempox = distanciax / .004;
    giro_negativo_x(x_paso, x_dire, x_habi);
  }
  if (distanciay >= 0) {
    tiempoy = distanciay / .004;
    giro_positivo_y(y_paso, y_dire, y_habi);
  }
  if (distanciay < 0) {
    distanciay = -(distanciay);
    tiempoy = distanciay / .004;
    giro_negativo_y(y_paso, y_dire, y_habi);
  }
  impresion();
}

void regar()
{
  analogWrite(16,255);
  delay(1000);
  analogWrite(16,0);
  delay(100);
}

void giro_positivo_x(int paso_, int dire_, int habi_) {
  digitalWrite(habi_, LOW);  // Habilita el Driver
  digitalWrite(dire_, LOW);   // direccion de giro 1
  for (int i = 0; i < tiempox; i++) { // da  pasos por un tiempo
    digitalWrite(paso_, HIGH);
    delayMicroseconds(retardo);
    digitalWrite(paso_, LOW);
    delayMicroseconds(retardo);
  }
  digitalWrite(habi_, HIGH);   // quita la habilitacion del Driver
}

void giro_negativo_x(int paso_, int dire_, int habi_) {
  digitalWrite(habi_, LOW);
  digitalWrite(dire_, HIGH);
  for (int i = 0; i < tiempox; i++) {
    digitalWrite(paso_, HIGH);
    delayMicroseconds(retardo);
    digitalWrite(paso_, LOW);
    delayMicroseconds(retardo);
  }
  digitalWrite(habi_, HIGH);
}
void giro_positivo_y(int paso_, int dire_, int habi_) {
  digitalWrite(habi_, LOW);  // Habilita el Driver
  digitalWrite(dire_, LOW);   // direccion de giro 1
  for (int i = 0; i < tiempoy; i++) { // da  pasos por un tiempo
    digitalWrite(paso_, HIGH);
    delayMicroseconds(retardo);
    digitalWrite(paso_, LOW);
    delayMicroseconds(retardo);
  }
  digitalWrite(habi_, HIGH);   // quita la habilitacion del Driver
}

void giro_negativo_y(int paso_, int dire_, int habi_) {
  digitalWrite(habi_, LOW);
  digitalWrite(dire_, HIGH);
  for (int i = 0; i < tiempoy; i++) {
    digitalWrite(paso_, HIGH);
    delayMicroseconds(retardo);
    digitalWrite(paso_, LOW);
    delayMicroseconds(retardo);
  }
  digitalWrite(habi_, HIGH);
}
