#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
using namespace std;

bool isAsal(int a) {
    if (a < 2) {
        return false;
    }

    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return false;
        }
    }

    return true;
} /*Bu fonksiyon sayesinde bir sayının asal olup olmadığını kontrol ediyoruz. */

void chatterCallback (const std_msgs::String::ConstPtr msg){
    int sayi;
    sayi=stoi(msg->data); /*Burada publisher'dan aldığımız string veriyi integer'a çevirerek 'sayi' değişkenine atıyoruz. */

    if(isAsal(sayi)){ /*Buradaki koşul sayesinde eğer sayının asal olup olmamasına göre çıktı veriyoruz. */
        ROS_INFO("Asal Sayi: [%s]", msg->data.c_str());
    }
    else{
        ROS_INFO("Asal Sayi Degil: [%s]", msg->data.c_str());
    }
} /*Bu fonksiyon, 'subscriber'ın bir topic üzerinden alınan mesajları işlemek için kullanılır. */

int main(int argc, char **argv){
    ros::init(argc,argv,"Subscriber");

    ros::NodeHandle n;
    
    ros::Subscriber sub = n.subscribe ("Deneme",1000,chatterCallback); /*Bir 'subscriber' oluşturur ve "Deneme" adındaki topic'i dinlemeye başlar.
    Daha sonra 'chatterCallBack' adlı fonksiyonu çağırır ve fonksiyon dinlenen topic'e göre çıktı verir. */

    ros::spin(); /*Düğümün döngü halinde çalışmasını sağlar. Dinlenen konulara göre fonksiyonları çağırmayı sağlar. */

    return 0;



}