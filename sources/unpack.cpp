#include "pugixml.hpp"
#include <iostream>


struct Email {
    std::string nickname;
    std::string server;
};

struct Person {
    std::string first_name;
    std::string last_name;
    Email email;
    size_t age;
    std::string phone;
};


void ReadFromFile( const char *path){
    pugi::xml_document doc;
    std::string str = "first_name";
    pugi::xml_parse_result result = doc.load_file(path);
    pugi::xml_node tool = doc.child("Person");
    std::cout<<"Person"<<std::endl;
    char *name = "first_name";
    std::cout <<"Fisrt name: " <<tool.child_value(name) << std::endl;
    char *family = "last_name";
    std::cout << "Last name: "<<tool.child_value(family) << std::endl;
    char *email = "Email";
    char *server = "server";
    char *nickname = "nickname";
    std::cout<<"Email:"<< tool.child(email).child_value(nickname)<<"@"<< tool.child(email).child_value(server) << std::endl;;

    char *age = "age";
    if(tool.child_value(age)!=""){
        std::cout <<"Age: " <<tool.child_value(age) << std::endl;
    }
    char *phone = "phone";
    if(tool.child_value(phone)!=""){
        std::cout <<"Phone: "<< tool.child_value(phone) << std::endl;
    }

}

int main(int argc, char *argv[]) {
    char* path = argv[1];
    ReadFromFile(path);
    return 0;
}
