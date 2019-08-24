#ifndef PESSOA_H
#define PESSOA_H

#include <string.h>

class Pessoa {
private:
    unsigned int id;
    char nome[30];
    char cidade[20];

public:
    Pessoa(const unsigned int i, const char n[], const char c[]) { id = i; strcpy(nome, n); strcpy(cidade, c); }
    unsigned int get_id() const { return id; }
    char* get_nome() { return nome; }
    char* get_cidade() { return cidade; }
};

#endif // PESSOA_H
