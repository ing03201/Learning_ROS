/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>

ros::NodeHandle  nh;

// variables will change:
static int ledNum = 0;

void displayLeds(int led)
{
    int i;
    led--;
    led %= 4;
    for(i=0;i<4;i++)
    {
       if(i == led)
          digitalWrite(BDPIN_LED_USER_1+i, LOW);
       else      
          digitalWrite(BDPIN_LED_USER_1+i, HIGH);
    }
}


void messageCb( const std_msgs::Int32& num){

   ledNum = num.data;
   displayLeds(ledNum);
}

ros::Subscriber<std_msgs::Int32> sub("display_led", messageCb );



std_msgs::String str_msg;
ros::Publisher result("result_led", &str_msg);

const int ledPin =  BDPIN_LED_USER_1;      // the number of the LED pin


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin+1, OUTPUT);
  pinMode(ledPin+2, OUTPUT);
  pinMode(ledPin+3, OUTPUT);
 
  nh.initNode();
  nh.advertise(result);
  nh.subscribe(sub);
  
  delay(100);
  //digitalWrite(BDPIN_LED_USER_1, LOW); 
}

void loop()
{
  char result_led[15];
  sprintf(result_led,"%d led ON", ledNum);  
  str_msg.data = result_led;
  result.publish( &str_msg );
  nh.spinOnce();
  delay(100);
}
