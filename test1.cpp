#include <iostream>
#include <ctime>

using namespace std;


string time_tell(int y){
    //output current time
    
    time_t currentTime;
    struct tm *localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    string op =asctime(localTime);

    if (y == 1) return op.substr(11,8);
    else if( y == 2) return op.substr(11,2) + "" + op.substr(14,2)+ "" + op.substr(17,2);
    return "fgg"; 
}

int main() {
    cout<< time_tell(2);

}
// + op.substr(15,2)


    // fle<<"Cs411644/Jodi Johnson/valerie55/0fe!mKya!3/077 567418"<<endl; 
    // fle<<"Cs711905/Rachel Brown/anthony32/9qv6_bLd$v/077 9505559"<<endl; 
    // fle<<"Cs933519/Samantha Hamilton/salazarkeith/$$FfINl)C9/077 7379211"<<endl; 
    // fle<<"Cs502522/Paula Meyer/gspencer/89Jofgl3@$/077 8418688 "<<endl;
    // fle<<"Cs482311/David Lewis/jeremiah73/(P7aRR#nsu/077 3701810"<<endl; 
    // fle<<"Cs749543/Richard Walker/tiffanymathews/#4(D2aPIt5/077 5020262"<<endl; 
    // fle<<"Cs514510/Frances Santiago/ryanflores/^&QltAp*M0/077 6068951"<<endl; 
    // fle<<"Cs110868/Olivia Lewis/ryan11/!p9IgIvIiL/077 2247163"<<endl; 
    // fle<<"Cs870608/Sheri Vargas/kimberly54/lRL1X#*d+4/077 6412117"<<endl; 
    // fle<<"Cs913368/Jose Schmidt/teresa19/^)32ZXny_9/077 9438763"<<endl; 
    // fle<<"Cs812356/Mrs. Denise Warner DDS/starklisa/GmFU7d9q_6/077 8990026"<<endl; 
    // fle<<"Cs202713/Amanda Fowler/bscott/(&9tSmHiFG/077 1886405"<<endl; 
    // fle<<"Cs176534/James Sanders/lbarker/rKdvxxD#$0/077 1784179"<<endl; 
    // fle<<"Cs231487/Amanda Cole/darryl35/Y8JcBP)c#&/077 1823584"<<endl;
    // fle<<"Cs349592/Joe Bean/eric97/s+I9P$0mi6/077 6073334"<<endl; 
    // fle<<"Cs687412/Matthew Lynn/michaelbrennan/^sYwfr261L/077 2596310"<<endl; 
    // fle<<"Cs825110/Brian Villarreal/pearsonmichael/+m8iN(WjTJ/077 9970134"<<endl; 
    // fle<<"Cs294692/Kim Noble/johnperkins/0vYDM7mc%z/077 7999827"<<endl; 
    // fle<<"Cs881949/Cassandra Johnson/rodriguezcarol/C52OK5$l^J/077 2196626"<<endl; 
    // fle<<"Cs312418/Philip Bautista/claudiagreen/*0j&0Uu#x&/077 1871678"<<endl; 