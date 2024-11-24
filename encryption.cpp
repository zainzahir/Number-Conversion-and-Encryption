#include<iostream>
using namespace std;
//header Menus
void mainHeader(); 
void numberConversionheader();
void encryptionHeader();
//functions
int power(int x, int y);
string decimalToString(int num);
//<------Number system--------------->
string decimalToBase(int num, int conversionBase);
int baseToDecimal(int num, int base);
int hexaToDecimal(string hexNum);
void numberConversionsystem(char choice,int &num,string &hexNum);
//<-----------Encryption and decryption system----------------->
void encryption(string str, int ascii[],int size); //for encryption
string decryption(string encryptedStr); //for decryption
//for encryption and decryption specific base system
void encryptionSystem(char choice, int ascii[],int size);

int main(){
    char choice;
    int num;
    string decrypted ="";
    string hexNum;
    int size = 100; //size of array
    int ascii[size] = {0};
    do{
        mainHeader();
        cout<<"\n\nSelect your desired option : ";
        cin>>choice;
        switch (choice){
            case '1':{ //Number Conversion system
                numberConversionsystem(choice,num,hexNum);
                break;
            }
            case '2':{ //Encryption & Decryption
                encryptionSystem(choice,ascii,size);
                break;
            }
            case '0':{ //exit
                cout<<"Thank you, Exit successfully.";
                break;
            }
            default:
                cout<<"Invalid choice!";
                break;
        }
        
    }while(choice!='0');
    return 0;
}
//<---------------number conversion-------------------------->
void numberConversionsystem(char choice,int &num,string &hexNum){
    do{
        numberConversionheader();
        cout<<"Select the input number system : ";
        cin>>choice;
        switch(choice){
            case '1':{ //binary
                cout<<"Enter the number : ";
                cin>>num;
                num = baseToDecimal(num,2); //number is now in decimal
                cout<<"Decimal : "<<num<<endl;
                cout<<"Octal : "<<decimalToBase(num,8)<<endl;
                cout<<"Hexadecimal : "<<decimalToBase(num,16)<<endl;
                system("pause");
                break;
            }
            case '2':{ //octal
                cout<<"Enter the number : ";
                cin>>num;
                num = baseToDecimal(num,8); //number is now in decimal
                cout<<"Binary : "<<decimalToBase(num,2)<<endl;
                cout<<"Decimal : "<<num<<endl;
                cout<<"Hexadecimal : "<<decimalToBase(num,16)<<endl;
                system("pause");
                break;
            }
            case '3':{ //decimal
                cout<<"Enter the number : ";
                cin>>num;
                cout<<"Binary : "<<decimalToBase(num,2)<<endl;
                cout<<"Octal : "<<decimalToBase(num,8)<<endl;
                cout<<"Hexadecimal : "<<decimalToBase(num,16)<<endl;
                system("pause");
                break;
            }
            case '4':{ //hexadecimal
                cout<<"Enter the number : ";
                cin>>hexNum;
                num = hexaToDecimal(hexNum); //number is now in decimal
                cout<<"Binary : "<<decimalToBase(num,2)<<endl;
                cout<<"Octal : "<<decimalToBase(num,8)<<endl;
                cout<<"Decimal : "<<num<<endl;
                system("pause");
                break;
            }
            case '0':
                break;
            default:{
                cout<<"Invalid choice!"<<endl;
                system("pause");
            }
        }
    }while(choice!='0');
}
//<--------------------Encryption function-------------------->
void encryptionSystem(char choice, int ascii[],int size){
    string str;
    int encryptSystem = 0;
    do{
        encryptionHeader();
        cout<<"Select the desired option : ";
        cin>>choice;
        switch(choice){
            case '1':{ //binary
                cout<<"\nChoose the number system in which you wanna encrypt your message : \n";
                cout<<"1. Binary   2. Octal   3. Decimal  4. Hexadecimal"<<endl;
                cout<<"Enter : ";
                cin>>encryptSystem;
                 cout<<"\nEnter the string you want to encrypt : ";
                 cin.ignore();
                getline(cin,str);
                encryption(str,ascii,size); //encrption in ascii decimal & stores in ascii array
                if(encryptSystem == 1){ //binary
                    cout<<"\nEncrypted message in binary : "<<endl;
                    for(int i=0; i<size; i++){
                        if(ascii[i]!=0){
                            cout<<decimalToBase(ascii[i],2)<<" ";
                        }
                        else{
                            break;
                        }
                    }
                }
                else if(encryptSystem == 2){ //octal
                    cout<<"\nEncrypted message in octal : "<<endl;
                    for(int i=0; i<size; i++){
                        if(ascii[i]!=0){
                            cout<<decimalToBase(ascii[i],8)<<" ";
                        }
                        else{
                            break;
                        }
                    }
                }
                else if(encryptSystem == 3){
                    cout<<"\nEncrypted message in decimal ascii : "<<endl;
                    for(int i=0; i<size; i++){
                        if(ascii[i]!=0){
                            cout<<ascii[i]<<" ";
                        }
                        else{
                            break;
                        }
                    }
                }
                else if(encryptSystem == 4){ //hexadecimal
                    cout<<"\nEncrypted message in Hexadecimal : "<<endl;
                    for(int i=0; i<size; i++){
                        if(ascii[i]!=0){
                            cout<<decimalToBase(ascii[i],16)<<" ";
                        }
                        else{
                            break;
                        }
                    }
                }
                else{
                    cout<<"Invalid choice!\n";
                }
                cout<<endl<<endl;
                system("pause");
                break;
            }
            case '2':{ 
                cout<<"\nChoose the number system for your pre-encrypted message : \n";
                cout<<"1. Binary   2. Octal   3. Decimal  4. Hexadecimal"<<endl;
                cout<<"Enter : ";
                cin>>encryptSystem;
                cout<<"Enter the string you want to decrypt : ";
                cin.ignore();
                getline(cin,str);
                if(encryptSystem == 1){ //binary
                    cout<<"\nDecrypted message : "<<endl;
                    for(int i=0; i<size; i++){
                        if(ascii[i]!=0){
                            cout<<decimalToBase(ascii[i],2)<<" ";
                        }
                        else{
                            break;
                        }
                    }
                }
                else if(encryptSystem == 2){ //octal
                    cout<<"\nDecrypted message : "<<endl;
                    
                }
                else if(encryptSystem == 3){ //decimal
                    cout<<"\nDecrypted message : "<<endl;
                            cout<<decryption(str)<<endl;
                }
                else if(encryptSystem == 4){ //hexadecimal
                    cout<<"\nDecrypted message : "<<endl;
                    
                }
                else{
                    cout<<"Invalid choice!\n";
                }
                cout<<endl<<endl;
                system("pause");
                break;
            }
            case '0':{
                break;
            }
            default:{
                cout<<"Invalid choice!"<<endl;
                system("pause");
            }
        }
    }while(choice!='0');
}
void encryption(string str, int ascii[],int size){
    string encryptStr = "";
    for(int i=0; i<str.length(); i++){
        if(str[i]>='A' && str[i]<='Z'){
            ascii[i] = str[i] - 'A'  + 65; //converts into decimal acsii
        }
        else if(str[i]>='a' && str[i]<='z'){
            ascii[i] = str[i] - 'a'  + 97; //converts into decimal acsii
        }
        // encryptStr += decimalToString(ascii) + " ";
        else if(str[i]==' '){
            ascii[i] = 32;
        }
        else if(str[i]=='.'){
            ascii[i] = 46;
        }
    }
    // return encryptStr;
}
string decimalToString(int num) {
    string result = "";
    while(num!=0){
        int lastDigit = num % 10; //extract last digit
        num = num / 10; //removes last digit
        result = static_cast<char>(lastDigit + '0') + result;
    }
    return result;
}
string decryption(string encryptedStr) {
    string decrypted = "";
    string temp = "";

    for(int i = 0; i < encryptedStr.length(); i++){
        if (encryptedStr[i] != ' ') {
            temp += encryptedStr[i]; //extrat 1st value
        }else {
            if (temp != "") {
                int ascii = 0;

                // convert to int ascii
                for (int j = 0; j < temp.length(); j++){
                    ascii = ascii * 10 + (temp[j] - '0');
                }

                // Convert the ASCII to char
                decrypted += static_cast<char>(ascii);
                temp = ""; 
            }
        }
    }

    // Handle last digit
    if(temp != ""){
    int ascii = 0;
        for (int j = 0; j < temp.length(); j++){
            ascii = ascii * 10 + (temp[j] - '0');
        }
        decrypted += static_cast<char>(ascii);
    }

    return decrypted;
}

//<-----------------number system conversion-------------------------->
//decimal to bin, oct and hex
string decimalToBase(int num, int conversionBase){
    string result = "";
    int lastDigit = 0;
    int i = 1;
    if(num == 0) //if user enter 0
        return "0";
    while (num!=0){
        lastDigit = num % conversionBase;
        num = num / conversionBase;
        if(lastDigit<10){
            result = char(lastDigit + '0') + result;
        }
        else{
            result = char(lastDigit - 10 + 'A') + result;
        }
    }
    return result;
}
// any base to decimal except hex
int baseToDecimal(int num, int base){
    int result = 0, i = 0, lastDigit = 0;
    if(num == 0) //if user enter 0
        return 0;
    while(num!=0){
        lastDigit = num % 10;
        num = num / 10;
        result = result + lastDigit*power(base,i);
        i++;
    }
    return result;
}
int hexaToDecimal(string hexNum){
    int result = 0, lastDigit = 0;
    int toPower = 0;
    for(int i=hexNum.length()-1; i>=0; i--){
        if(hexNum[i]>='0' && hexNum[i]<='9'){
            lastDigit = hexNum[i] - '0';
            result += lastDigit*power(16,toPower);
            toPower++;
        }
        else if(hexNum[i]>='A' && hexNum[i]<='F'){
            lastDigit = hexNum[i] - 'A' + 10;
            result += lastDigit*power(16,toPower);
            toPower++;
        }
    }
    return result;
}
//calculate power
int power(int x, int y){
    int power = 1;
    for(int i=1; i<=y; i++){
        power *= x;
    }
    return power;
}

//<------------------------interfaces-------------------------->
void mainHeader(){
    system("cls");
    cout<<"************************************************"<<endl;
    cout<<"   ----- Number Conversion & Encryption -----   "<<endl;
    cout<<"************************************************"<<endl;
    cout<<"1. Number Conversion system"<<endl;
    cout<<"2. Encryption & Decryption"<<endl;
    cout<<"0. Exit"<<endl;
}
void numberConversionheader(){
    system("cls");
    cout<<"************************************************"<<endl;
    cout<<"     ------ Number Conversion system ------     "<<endl;
    cout<<"************************************************"<<endl;
    cout<<"1. Binary"<<endl;
    cout<<"2. Octal"<<endl;
    cout<<"3. Decimal"<<endl;
    cout<<"4. Hexadecimal"<<endl;
    cout<<"0. Exit"<<endl;
}
void encryptionHeader(){
    system("cls");
    cout<<"************************************************"<<endl;
    cout<<"     ------ Encryption & Decryption  ------     "<<endl;
    cout<<"************************************************"<<endl;
    cout<<"1. Encryption"<<endl;
    cout<<"2. Decryption"<<endl;
    cout<<"0. Exit"<<endl;
}
