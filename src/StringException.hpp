//
// Created by ben on 4/14/17.
//

#ifndef CONNAN_STRINGEXCEPTION_HPP
#define CONNAN_STRINGEXCEPTION_HPP

#include <string>
#include <exception>

class StringException : public std::exception {
private:
    std::string reason;

public:
    StringException(std::string _reason) : reason(_reason) {}

    virtual const char *what() const noexcept override {
        return reason.c_str();
    }
};


#endif //CONNAN_STRINGEXCEPTION_HPP
