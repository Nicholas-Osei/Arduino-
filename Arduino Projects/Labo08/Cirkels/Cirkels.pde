import processing.serial.*;

Serial myPort;  
int val = 0;      

void setup() {
  size(1000 , 800); 
  background(200); // achtergronds kleur
  ellipseMode(CENTER); //Wijzigt de locatie vanwaaruit ellipsen worden getekend door de manier te wijzigen waarop parameters die aan ellips () worden gegeven, worden geïnterpreteerd.
  fill(255);
  ellipse( 400, 300, 200, 200); //grotte van de cirkel
  textSize(12);
  fill(0);
  textAlign(CENTER); // tekst wordt in het midden gecentreerd 
  text("push a button", 400, 300); //grotte van het tekst in de cirkel
  

  val = Serial.list().length; // val krijgt alle beschikbare seriale poorten en geeft geeft de lengte door
  if(val == 0){
    println("Geen seriële poorten gevonden");
    exit();
    return;
  }else if(val > 1){
    println("Meer dan 1 seriële poort gevonden.");
  }
  println("Seriële poorten gedetecteerd: ");
  for(int i=0; i<val; i++)
  {
    print(i + ": "); // hier worden alle poorten weergegeven
    println(Serial.list()[i]);// de geselecteerde poort wordt hier weergegeven
  }
  myPort = new Serial(this, "/dev/cu.usbserial-A906OS2G", 9600); // uw selecteerde port wordt hier gebruikt om de code naar de arduino nano te sturen. Omdat ik een macbook heb moest ik deze aanpassen. 
  println("Seriële poort geselecteerd: " + Serial.list()[0]); 

} 

void draw () { 
  if ( myPort.available() > 0) {        
    val = myPort.read();                 
  }
  
  if( val == '1' ){ // als 1 verstuurd wordt zal x een random getal genereren tussen 0 en 800
    float x = random(800);
    float y = random(600); //y zal  een random getal genereren tussen 0 en 600
    float r = random(50)+10; // r zal  een random getal genereren tussen 10 en 50
    fill( random(255), random(255), random(255)); // cirkel wordt gevuld met een bepaalde achtergrond
    ellipse( x, y, r, r); //cirkel wordt getekent
    val = 0; // val wordt gereset
  }
  
  if( val == '2' ){  // als 2 verstuurd wordt zal achtergrond de waarde 200 ontvangen en val wordt gereset
    background(200);
    val = 0;
  }
}
