import controlP5.*;
import meter.*;
import processing.serial.*;

Serial myPort; 
Meter m;
ControlP5 controlP5;
Knob LED;
void setup() {
  size(1200,500);
  smooth();
  noStroke();
  
  m = new Meter(this, 600, 100); // full circle - true, 1/2 circle - false  
  myPort = new Serial(this, "COM3", 9600);
  controlP5 = new ControlP5(this);
  
  LED = controlP5.addKnob("LED")
               .setRange(0,255)
               .setValue(0)
               .setPosition(80,100)
               .setRadius(150)
               .setNumberOfTickMarks(51)
               .setTickMarkLength(10)
               .snapToTickMarks(true)
               .setColorForeground(color(255))
               .setColorBackground(color(0, 160, 100))
               .setColorActive(color(255,255,0))
               .setDragDirection(Knob.HORIZONTAL)
               ;
}

void draw() {
  if ( myPort.available() > 0) {       
     int val = myPort.read();
    println(val);
    m.updateMeter(val);
  }
}

void LED(int LED)
{
  myPort.write(LED);
  println(LED);
}
