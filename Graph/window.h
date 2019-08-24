#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QProgressBar>
#include "dados.h"
#include "grafo.h"
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <random>

class window : public QWidget {

public:
    explicit window(QWidget *parent = nullptr);

private:
    QWidget *new_window;
    QLineEdit *campo_texto1;
    QLineEdit *campo_texto2;
    QLabel *alert;
    QProgressBar *progressBar;

private slots:
    void tela_add_pes();
    void tela_perf_indiv();
    void tela_graf_aleat();
    void tela_add_relac();
    void tela_bfs_sp();
    void tela_dfs_sp();
    void tela_bfs_con();
    void tela_dfs_con();
    void adicionar_pessoa();
    void perfil_individual();
    void grafo_aleatorio();
    void adicionar_relacionamento();
    void bfs_sp();
    void dfs_sp();
    void bfs_connection();
    void dfs_connection();
};

#endif // WINDOW_H
