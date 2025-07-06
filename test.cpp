#include <filesystem>
#include<iostream>
main(){

    std::cout << "CWD: " << std::filesystem::current_path() << '\n';
    std::cout << "Font exists? " << std::filesystem::exists("Roboto-Regular.ttf") << '\n';
}
