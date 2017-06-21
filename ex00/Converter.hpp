#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include "float.h"
#include <iomanip>

class Converter{
public:
    Converter(void);
    Converter(std::string chaine);
    Converter( Converter const & src);
    virtual ~Converter(void);
    Converter & operator=(Converter const &rhs);
    std::string getChaine(void);
    void searchType(std::string chaine);
    void goInt(int val);
    void goFloat(float val, int decimal);
    void goDouble(double val, int decimal);
    void goChar(char val);
private:
    int _size;
    std::string _chaine;
};
#endif
