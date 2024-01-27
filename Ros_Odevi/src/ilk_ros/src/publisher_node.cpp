#include "ros/ros.h" /*ROS'un c++ için özel kütüphanesini dahil eder. */
#include "std_msgs/String.h" /*Metin tabanlı veri yayınlamak için kullanılan bir kütüphanedir. */
#include <sstream> /*Veri türlerini metine çevirmek için kullanılır. */
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    ros::init(argc,argv,"Publisher"); /*Bu satır ROS kütüphanesini başlatır. */

    ros::NodeHandle n; /*Bu satır bir düğüm oluşturmayı sağlar ve diğer ROS işlemleri ile iletişim kurmayı sağlar. */

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("Deneme",1000); /*Bu satırda 'n' nesnesi üzerinden bir "publisher" 
    oluşturulur. Bu "publisher" std_msgs::String türündeki mesajları "Deneme" adındaki ROS Topic'e yayınlar.*/

    ros::Rate loop_rate(1); /*Bu satır döngülerin belirli bir frekans ile çalışmasını sağlar.
    10 ile belirtilen değer ise bu döngünün saniyede 10 kez çalışacağını gösterir. */

    int count = 0; /*Döngü için sayaç oluşturulur ve sayacın döngü içinde her defasında artması sağlanır. */

    while (ros::ok()){ /*Döngü içine girilen 'ros::ok()' komutu ile döngü, kullanıcı sonlandırana kadar çalışır. İsteğe bağlı olarak bu koşul 
    değiştirilebilir. */

        std_msgs::String msg; /*'msg' adında bir nesne oluşturulur ve daha sonrasında bu nesneye metin ataması yapılabilir.*/

        std::stringstream ss; /* 'ss' adında bir nesne oluşturulur ve bu nesne okuma ve yazma işlemlerini gerçekleştirebilir. */
        
        ss << count;
        
        msg.data = ss.str(); /*Bu satır 'ss' içine yazılan metin verisini 'msg' içine atmayı sağlar.*/

        ROS_INFO("%s", msg.data.c_str()); /*Bu kod satırı, ROS içindeki ROS_INFO makrosunu kullanarak bir bilgi (info) log mesajı yazdırmak için kullanılır. */

        chatter_pub.publish(msg); /*Bu satır programın bir mesaj yayınlamasını sağlar. */

        ros::spinOnce(); /*Bu fonksiyon, genellikle ROS düğümünün ana döngüsü içinde kullanılır ve callback fonksiyonlarının düzenli aralıklarla
        çağrılmasını sağlar.*/

        loop_rate.sleep(); /*Bu satır ile de isteğe bağlı olarak döngünün çalışma hızı sınırlanabilir. */

        ++count;
    }

    return 0;
}