#include "window.h"

#include <QPushButton>
#include <QGridLayout>
#include <QFont>
#include <QEventLoop>
#include <QGroupBox>
#include <QFormLayout>
#include <QValidator>
#include <QMessageBox>
#include <ctime>

window::window(QWidget *parent) : QWidget(parent) {
    int button_size = 420;
    int maximum_label_height = 30;
    QFont buttonFont("Times", 20);
    QFont labelFont("Times", 20, QFont::Bold);

    QVBoxLayout *tela = new QVBoxLayout(this);
    QGridLayout *indiv_colet = new QGridLayout();
    QGridLayout *complexos = new QGridLayout();

    /**************** INDIVIDUAL *********************/

    QLabel *indiv_label = new QLabel("INDIVIDUAL", this);
    indiv_colet->addWidget(indiv_label, 0, 0);
    indiv_label->setAlignment(Qt::AlignCenter);
    indiv_label->setMaximumHeight(maximum_label_height);
    indiv_label->setFont(labelFont);

    QPushButton *add_indiv = new QPushButton("Adicionar Pessoa", this);
    add_indiv->setFixedWidth(button_size);
    add_indiv->setFont(buttonFont);
    connect(add_indiv, &QPushButton::clicked, this, &window::tela_add_pes);
    indiv_colet->addWidget(add_indiv, 1, 0);

    QPushButton *perfil = new QPushButton("Buscar Perfil", this);
    perfil->setFixedWidth(button_size);
    perfil->setFont(buttonFont);
    connect(perfil, &QPushButton::clicked, this, &window::tela_perf_indiv);
    indiv_colet->addWidget(perfil, 2, 0);

    /**************** COLETIVO *********************/

    QLabel *colet_label = new QLabel("COLETIVO", this);
    indiv_colet->addWidget(colet_label, 0, 1);
    colet_label->setAlignment(Qt::AlignCenter);
    colet_label->setMaximumHeight(maximum_label_height);
    colet_label->setFont(labelFont);

    QPushButton *random_graph = new QPushButton("Gerar Grafo Aleatório", this);
    random_graph->setFixedWidth(button_size);
    random_graph->setFont(buttonFont);
    connect(random_graph, &QPushButton::clicked, this, &window::tela_graf_aleat);
    indiv_colet->addWidget(random_graph, 1, 1);

    QPushButton *relacao = new QPushButton("Adicionar Relacionamento", this);
    relacao->setFixedWidth(button_size);
    relacao->setFont(buttonFont);
    connect(relacao, &QPushButton::clicked, this, &window::tela_add_relac);
    indiv_colet->addWidget(relacao, 2, 1);

    /**************** BFS *********************/

    QLabel *bfs = new QLabel("BFS", this);
    complexos->addWidget(bfs, 0, 0);
    bfs->setAlignment(Qt::AlignCenter);
    bfs->setMaximumHeight(maximum_label_height);
    bfs->setFont(labelFont);

    QPushButton *shortest_bfs = new QPushButton("Menor Caminho entre duas Pessoas", this);
    shortest_bfs->setFixedWidth(button_size);
    shortest_bfs->setFont(buttonFont);
    connect(shortest_bfs, &QPushButton::clicked, this, &window::tela_bfs_sp);
    complexos->addWidget(shortest_bfs, 1, 0);

    QPushButton *connection_bfs = new QPushButton("Conexão entre uma Pessoa e as outras", this);
    connection_bfs->setFixedWidth(button_size);
    connection_bfs->setFont(buttonFont);
    connect(connection_bfs, &QPushButton::clicked, this, &window::tela_bfs_con);
    complexos->addWidget(connection_bfs, 2, 0);

    /**************** DFS *********************/

    QLabel *dfs = new QLabel("DFS", this);
    complexos->addWidget(dfs, 0, 1);
    dfs->setAlignment(Qt::AlignCenter);
    dfs->setMaximumHeight(maximum_label_height);
    dfs->setFont(labelFont);

    QPushButton *shortest_dfs = new QPushButton(" ??? ", this);
    shortest_dfs->setFixedWidth(button_size);
    shortest_dfs->setFont(buttonFont);
    connect(shortest_dfs, &QPushButton::clicked, this, &window::tela_dfs_sp);
    complexos->addWidget(shortest_dfs, 1, 1);

    QPushButton *connection_dfs = new QPushButton(" ??? ", this);
    connection_dfs->setFixedWidth(button_size);
    connection_dfs->setFont(buttonFont);
    connect(connection_dfs, &QPushButton::clicked, this, &window::tela_dfs_con);
    complexos->addWidget(connection_dfs, 2, 1);

    /********************** FINALIZAÇÕES *********************/

    QGroupBox *group_indiv_colet = new QGroupBox(this);
    QGroupBox *group_comp = new QGroupBox(this);

    group_indiv_colet->setLayout(indiv_colet);
    group_comp->setLayout(complexos);

    tela->addWidget(group_indiv_colet);
    tela->addWidget(group_comp);
    setLayout(tela);
}

void window::tela_add_pes() {
    new_window = new QWidget(nullptr);
    new_window->setFixedSize(500, 200);
    new_window->setWindowTitle("Adicionar Pessoa");

    QFont buttonFont("Times", 20);
    int button_size = 380;

    QFont labelFont("Times", 20, QFont::Bold);
    QFont campoFont("Times", 20);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLabel *main_label = new QLabel("Insira os dados da Pessoa");
    main_label->setFont(labelFont);
    main_label->setAlignment(Qt::AlignCenter);
    QLabel *label_nome = new QLabel("Nome:");
    label_nome->setFont(labelFont);
    QLabel *label_cidade = new QLabel("Cidade:");
    label_cidade->setFont(labelFont);

    campo_texto1 = new QLineEdit();
    campo_texto1->setFont(campoFont);
    campo_texto1->setMaxLength(30);

    campo_texto2 = new QLineEdit();
    campo_texto2->setFont(campoFont);
    campo_texto2->setMaxLength(20);

    formLayout->addWidget(main_label);
    formLayout->addRow(label_nome, campo_texto1);
    formLayout->addRow(label_cidade, campo_texto2);

    QPushButton *button = new QPushButton("Adicionar");
    button->setFixedWidth(button_size);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked, this, &window::adicionar_pessoa);

    alert = new QLabel("");
    alert->setAlignment(Qt::AlignCenter);
    alert->setMaximumHeight(20);

    formLayout->addWidget(button);
    formLayout->addWidget(alert);

    new_window->setLayout(formLayout);
    new_window->show();

    QEventLoop loop;
    connect(this, SIGNAL(destroyed()), & loop, SLOT(quit()));
    loop.exec();
}

void window::tela_perf_indiv() {
    new_window = new QWidget(nullptr);

    if(!nodes.size()) {
        QMessageBox::information(new_window, tr("Aviso"), tr("Não há nenhuma pessoa cadastrada"));
        return;
    }

    QFont buttonFont("Times", 20);
    QFont labelFont("Times", 20, QFont::Bold);
    QFont campoFont("Times", 20);
    int button_size = 480;
    int maximum_label_height = 30;

    campo_texto1 = new QLineEdit();
    campo_texto1->setFont(campoFont);
    campo_texto1->setValidator(new QIntValidator());

    new_window->setFixedSize(500, 300);
    new_window->setWindowTitle("Buscar Perfil");

    QVBoxLayout *tela = new QVBoxLayout();

    QLabel *label = new QLabel("Insira o ID da Pessoa");
    label->setAlignment(Qt::AlignCenter);
    label->setMaximumHeight(maximum_label_height);
    label->setFont(labelFont);

    QPushButton *button = new QPushButton("Enviar");
    button->setFixedWidth(button_size);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked, this, &window::perfil_individual);

    alert = new QLabel("");
    alert->setAlignment(Qt::AlignCenter);
    alert->setMaximumHeight(15);

    tela->addWidget(label);
    tela->addWidget(campo_texto1);
    tela->addWidget(button);
    tela->addWidget(alert);
    new_window->setLayout(tela);
    new_window->show();

    QEventLoop loop;
    connect(this, SIGNAL(destroyed()), & loop, SLOT(quit()));
    loop.exec();
}

void window::tela_graf_aleat() {
    new_window = new QWidget(nullptr);
    new_window->setFixedSize(750, 270);
    new_window->setWindowTitle("Gerar Grafo Aleatório");

    QFont buttonFont("Times", 20);
    int button_size = 520;

    QFont labelFont("Times", 20, QFont::Bold);
    QFont campoFont("Times", 20);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLabel *main_label = new QLabel("Insira quantas Pessoas e Relacionamentos");
    main_label->setFont(labelFont);
    main_label->setAlignment(Qt::AlignCenter);
    QLabel *label_pessoa = new QLabel("Pessoas:");
    label_pessoa->setFont(labelFont);
    QLabel *label_relacionamento = new QLabel("Relacionamentos:");
    label_relacionamento->setFont(labelFont);

    campo_texto1 = new QLineEdit();
    campo_texto1->setFont(campoFont);
    campo_texto1->setValidator(new QIntValidator());

    campo_texto2 = new QLineEdit();
    campo_texto2->setFont(campoFont);
    campo_texto2->setValidator(new QIntValidator());

    formLayout->addWidget(main_label);
    formLayout->addRow(label_pessoa, campo_texto1);
    formLayout->addRow(label_relacionamento, campo_texto2);

    QPushButton *button = new QPushButton("Enviar");
    button->setFixedWidth(button_size);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked, this, &window::grafo_aleatorio);

    alert = new QLabel("");
    alert->setAlignment(Qt::AlignCenter);
    alert->setMaximumHeight(20);

    progressBar = new QProgressBar();
    progressBar->setFixedHeight(40);

    formLayout->addWidget(button);
    formLayout->addWidget(progressBar);
    formLayout->addWidget(alert);

    new_window->setLayout(formLayout);
    new_window->show();

    QEventLoop loop;
    connect(this, SIGNAL(destroyed()), & loop, SLOT(quit()));
    loop.exec();
}

void window::tela_add_relac() {
    new_window = new QWidget(nullptr);

    if(nodes.size() < 2) {
        QMessageBox::information(new_window, tr("Aviso"), tr("São necessárias 2 pessoas no mínimo\npara uma relação"));
        return;
    }

    new_window->setFixedSize(500, 200);
    new_window->setWindowTitle("Adicionar Relacionamento");

    QFont buttonFont("Times", 20);
    int button_size = 365;

    QFont labelFont("Times", 20, QFont::Bold);
    QFont campoFont("Times", 20);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLabel *main_label = new QLabel("Insira os IDs das Pessoas");
    main_label->setFont(labelFont);
    main_label->setAlignment(Qt::AlignCenter);
    QLabel *label_p1 = new QLabel("Pessoa 1:");
    label_p1->setFont(labelFont);
    QLabel *label_p2 = new QLabel("Pessoa 2:");
    label_p2->setFont(labelFont);

    campo_texto1 = new QLineEdit();
    campo_texto1->setFont(campoFont);
    campo_texto1->setValidator(new QIntValidator());

    campo_texto2 = new QLineEdit();
    campo_texto2->setFont(campoFont);
    campo_texto2->setValidator(new QIntValidator());

    formLayout->addWidget(main_label);
    formLayout->addRow(label_p1, campo_texto1);
    formLayout->addRow(label_p2, campo_texto2);

    QPushButton *button = new QPushButton("Adicionar");
    button->setFixedWidth(button_size);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked, this, &window::adicionar_relacionamento);

    alert = new QLabel("");
    alert->setAlignment(Qt::AlignCenter);
    alert->setMaximumHeight(20);

    formLayout->addWidget(button);
    formLayout->addWidget(alert);

    new_window->setLayout(formLayout);
    new_window->show();

    QEventLoop loop;
    connect(this, SIGNAL(destroyed()), & loop, SLOT(quit()));
    loop.exec();
}

void window::tela_bfs_sp() {
    new_window = new QWidget(nullptr);

    if(nodes.size() < 2) {
        QMessageBox::information(new_window, tr("Aviso"), tr("São necessárias 2 pessoas no mínimo\npara usar essa opção"));
        return;
    }

    new_window->setFixedSize(500, 200);
    new_window->setWindowTitle("Menor Caminho entre duas Pessoas");

    QFont buttonFont("Times", 20);
    int button_size = 365;

    QFont labelFont("Times", 20, QFont::Bold);
    QFont campoFont("Times", 20);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLabel *main_label = new QLabel("Insira os IDs das Pessoas");
    main_label->setFont(labelFont);
    main_label->setAlignment(Qt::AlignCenter);
    QLabel *label_p1 = new QLabel("Pessoa 1:");
    label_p1->setFont(labelFont);
    QLabel *label_p2 = new QLabel("Pessoa 2:");
    label_p2->setFont(labelFont);

    campo_texto1 = new QLineEdit();
    campo_texto1->setFont(campoFont);
    campo_texto1->setValidator(new QIntValidator());

    campo_texto2 = new QLineEdit();
    campo_texto2->setFont(campoFont);
    campo_texto2->setValidator(new QIntValidator());

    formLayout->addWidget(main_label);
    formLayout->addRow(label_p1, campo_texto1);
    formLayout->addRow(label_p2, campo_texto2);

    QPushButton *button = new QPushButton("Pesquisar");
    button->setFixedWidth(button_size);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked, this, &window::bfs_sp);

    alert = new QLabel("");
    alert->setAlignment(Qt::AlignCenter);
    alert->setMaximumHeight(20);

    formLayout->addWidget(button);
    formLayout->addWidget(alert);

    new_window->setLayout(formLayout);
    new_window->show();

    QEventLoop loop;
    connect(this, SIGNAL(destroyed()), & loop, SLOT(quit()));
    loop.exec();
}

void window::tela_dfs_sp() {

}

void window::tela_bfs_con() {
    new_window = new QWidget(nullptr);

    if(nodes.size() < 2) {
        QMessageBox::information(new_window, tr("Aviso"), tr("São necessárias 2 pessoas no mínimo\npara usar essa opção"));
        return;
    }

    new_window->setFixedSize(450, 170);
    new_window->setWindowTitle("Menor Caminho entre duas Pessoas");

    QFont buttonFont("Times", 20);
    int button_size = 315;

    QFont labelFont("Times", 20, QFont::Bold);
    QFont campoFont("Times", 20);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QLabel *main_label = new QLabel("Insira o ID da Pessoa");
    main_label->setFont(labelFont);
    main_label->setAlignment(Qt::AlignCenter);
    QLabel *label_p1 = new QLabel("Pessoa 1:");
    label_p1->setFont(labelFont);

    campo_texto1 = new QLineEdit();
    campo_texto1->setFont(campoFont);
    campo_texto1->setValidator(new QIntValidator());

    campo_texto2 = new QLineEdit();
    campo_texto2->setFont(campoFont);
    campo_texto2->setValidator(new QIntValidator());

    formLayout->addWidget(main_label);
    formLayout->addRow(label_p1, campo_texto1);

    QPushButton *button = new QPushButton("Pesquisar");
    button->setFixedWidth(button_size);
    button->setFont(buttonFont);
    connect(button, &QPushButton::clicked, this, &window::bfs_connection);

    alert = new QLabel("");
    alert->setAlignment(Qt::AlignCenter);
    alert->setMaximumHeight(20);

    formLayout->addWidget(button);
    formLayout->addWidget(alert);

    new_window->setLayout(formLayout);
    new_window->show();

    QEventLoop loop;
    connect(this, SIGNAL(destroyed()), & loop, SLOT(quit()));
    loop.exec();
}

void window::tela_dfs_con() {

}

void window::adicionar_pessoa() {
    QString nome = campo_texto1->text();
    if(nome == "") {
        alert->setText("Nome não pode ser em branco");
        return;
    }

    QString cidade = campo_texto2->text();
    if(cidade == "") {
        alert->setText("Cidade não pode ser em branco");
        return;
    }

    nodes.push_back(Pessoa(nodes.size(), nome.toStdString().c_str(), cidade.toStdString().c_str()));
    new_window->close();
}

void window::perfil_individual() {
    unsigned int id = campo_texto1->text().toUInt();
    if(id >= nodes.size()) {
        alert->setText("Numero deve estar entre 0 e " + QString::number(nodes.size()-1));
        return;
    }

    Pessoa p = nodes[id];

    new_window->close();

    new_window = new QWidget(nullptr);

    QFont labelFont("Times", 20, QFont::Bold);
    int maximum_label_height = 30;

    QGridLayout *layout = new QGridLayout();

    QLabel *label_id = new QLabel("ID: ");
    QLabel *label_nome = new QLabel("Nome: ");
    QLabel *label_cidade = new QLabel("Cidade: ");
    QLabel *label_amigos = new QLabel("Amigos: ");

    QLabel *p_id = new QLabel(QString::number(p.get_id()));
    QLabel *p_nome = new QLabel(QString::fromStdString(p.get_nome()));
    QLabel *p_cidade = new QLabel(QString::fromStdString(p.get_cidade()));
    QLabel *p_amigos = new QLabel(QString::number(edges[id].size()));

    label_id->setMaximumHeight(maximum_label_height);
    label_id->setFont(labelFont);
    label_nome->setMaximumHeight(maximum_label_height);
    label_nome->setFont(labelFont);
    label_cidade->setMaximumHeight(maximum_label_height);
    label_cidade->setFont(labelFont);
    label_amigos->setMaximumHeight(maximum_label_height);
    label_amigos->setFont(labelFont);

    p_id->setMaximumHeight(maximum_label_height);
    p_id->setFont(labelFont);
    p_nome->setMaximumHeight(maximum_label_height);
    p_nome->setFont(labelFont);
    p_cidade->setMaximumHeight(maximum_label_height);
    p_cidade->setFont(labelFont);
    p_amigos->setMaximumHeight(maximum_label_height);
    p_amigos->setFont(labelFont);

    label_id->setAlignment(Qt::AlignRight);
    label_nome->setAlignment(Qt::AlignRight);
    label_cidade->setAlignment(Qt::AlignRight);
    label_amigos->setAlignment(Qt::AlignRight);

    layout->addWidget(label_id, 0, 0);
    layout->addWidget(label_nome, 1, 0);
    layout->addWidget(label_cidade, 2, 0);
    layout->addWidget(label_amigos, 3, 0);

    p_id->setAlignment(Qt::AlignLeft);
    p_nome->setAlignment(Qt::AlignLeft);
    p_cidade->setAlignment(Qt::AlignLeft);
    p_amigos->setAlignment(Qt::AlignLeft);

    layout->addWidget(p_id, 0, 1);
    layout->addWidget(p_nome, 1, 1);
    layout->addWidget(p_cidade, 2, 1);
    layout->addWidget(p_amigos, 3, 1);

    new_window->setWindowTitle(p.get_nome());
    new_window->setLayout(layout);
    new_window->setFixedSize(500, 200);
    new_window->show();

    QEventLoop loop;
    connect(this, SIGNAL(destroyed()), & loop, SLOT(quit()));
    loop.exec();
}

void window::grafo_aleatorio() {
    int n_nodes = campo_texto1->text().toInt();
    if(!n_nodes) {
        alert->setText("Quantidade de pessoas deve ser maior que 0");
        return;
    }
    int n_edges = campo_texto2->text().toInt();
    unsigned long long limite = n_nodes*n_nodes - n_nodes;
    if(n_edges > limite) {
        alert->setText("Quantidade de relacionamentos deve estar entre 0 e " + QString::number(limite));
        return;
    }

    random_device rd;
    mt19937_64 mt(rd());

    uniform_int_distribution<int> dist_cidades(0, N_CIDADES-1);
    uniform_int_distribution<int> dist_nomes(0, N_NOMES-1);
    uniform_int_distribution<int> dist_sobrenomes(0, N_SOBRENOMES-1);
    uniform_int_distribution<int> dist_edges(0, n_nodes-1);

    nodes.clear();
    nodes.reserve(n_nodes);
    edges.clear();
    edges.resize(n_nodes);

    progressBar->setMinimum(0);
    progressBar->setMaximum(n_nodes);
    progressBar->setValue(0);

    int um_perc = n_nodes/100 ? n_nodes/100 : 1;

    alert->setText("Adicionando Pessoas");

    for(int i = 0; i < n_nodes; ++i) {
        nodes.emplace_back(i, (string(nomes[dist_nomes(mt)]) + " " + string(sobrenomes[dist_sobrenomes(mt)])).c_str(), cidades[dist_cidades(mt)]);
        if(!(i%um_perc)) progressBar->setValue(i);
    }

    progressBar->setValue(0);
    progressBar->setMinimum(0);
    progressBar->setMaximum(n_edges);

    um_perc = n_edges/100 ? n_edges/100 : 1;

    alert->setText("Adicionando Relacionamentos");

    if(n_edges != limite) {
        for(int i = 0; i < n_edges; ++i) {
            unsigned int x, y;
            bool repetido;
            do {
                repetido = false;
                x = dist_edges(mt);
                y = dist_edges(mt);
                for(auto it = edges[x].cbegin(); it != edges[x].cend(); ++it) {
                    Pessoa *p = *it;
                    if(p->get_id() == y) {
                        repetido = true;
                        break;
                    }
                }
            } while(repetido);

            edges[x].push_back(&nodes[y]);
            edges[y].push_back(&nodes[x]);
            if(!(i%um_perc)) progressBar->setValue(i);
        }
    }
    else {
        int i = 0;
        for(int x = n_nodes; x--; )
            for(int y = n_nodes; y--; ) {
                edges[x].push_back(&nodes[y]);
                edges[y].push_back(&nodes[x]);
                i++;
                if(!(i%um_perc)) progressBar->setValue(i);
            }
    }

    new_window->close();
}

void window::adicionar_relacionamento() {
    unsigned int p1 = campo_texto1->text().toUInt();
    if(p1 >= nodes.size()) {
        alert->setText("Numero da Pessoa 1 deve estar entre 0 e " + QString::number(nodes.size()-1));
        return;
    }

    unsigned int p2 = campo_texto2->text().toUInt();
    if(p2 >= nodes.size()) {
        alert->setText("Numero da Pessoa 2 deve estar entre 0 e " + QString::number(nodes.size()-1));
        return;
    }

    if(p1 == p2) {
        alert->setText("Pessoas não podem ser as mesmas");
        return;
    }

    for(auto it = edges[p1].cbegin(); it != edges[p1].cend(); ++it) {
        Pessoa *p = *it;
        if(p->get_id() == p2) {
            alert->setText("Essas pessoas já se conhecem");
            return;
        }
    }

    edges[p1].push_back(&nodes[p2]);
    edges[p2].push_back(&nodes[p1]);

    new_window->close();
}

void window::bfs_sp() {
    unsigned int p1 = campo_texto1->text().toUInt();
    if(p1 >= nodes.size()) {
        alert->setText("Numero da Pessoa 1 deve estar entre 0 e " + QString::number(nodes.size()-1));
        return;
    }

    unsigned int p2 = campo_texto2->text().toUInt();
    if(p2 >= nodes.size()) {
        alert->setText("Numero da Pessoa 2 deve estar entre 0 e " + QString::number(nodes.size()-1));
        return;
    }

    if(p1 == p2) {
        alert->setText("Pessoas não podem ser as mesmas");
        return;
    }

    time_t tempo = clock();
    vector<int> path = BFS_Shortest_Distance(p1, p2);
    tempo = clock() - tempo;

    if(path[0] == -1) {
        alert->setText("Não há caminho entre essas duas pessoas");
        return;
    }

    new_window->close();

    QFont font("Times", 15, QFont::Bold);
    new_window = new QWidget(nullptr);
    QVBoxLayout *tela = new QVBoxLayout();

    QLabel *time_label = new QLabel("Tempo de Busca: " + QString::number(((float)tempo)/CLOCKS_PER_SEC, 'g', 6) + " segundos");
    time_label->setFont(font);
    time_label->setAlignment(Qt::AlignCenter);

    QListWidget *lista = new QListWidget();
    lista->setFont(font);

    for(size_t i = path.size()-1; i > 0; --i) {
        lista->addItem(QString::fromStdString(string(nodes[path[i]].get_nome())
                                              + " (" + to_string(nodes[path[i]].get_id())
                                              + ") conhece " + string(nodes[path[i-1]].get_nome())
                                              + " (" + to_string(nodes[path[i-1]].get_id())
                                              + ")"));
    }

    tela->addWidget(time_label);
    tela->addWidget(lista);
    new_window->setLayout(tela);
    new_window->setFixedSize(650, 330);
    new_window->show();

    QEventLoop loop;
    connect(this, SIGNAL(destroyed()), & loop, SLOT(quit()));
    loop.exec();
}

void window::dfs_sp() {

}

void window::bfs_connection() {
    unsigned int id = campo_texto1->text().toUInt();
    if(id >= nodes.size()) {
        alert->setText("Numero da Pessoa deve estar entre 0 e " + QString::number(nodes.size()-1));
        return;
    }
    time_t tempo = clock();
    vector<int> quantidades = complete_BFS_Shortest_Distance(id);
    tempo = clock() - tempo;

    new_window->close();

    QFont font("Times", 15, QFont::Bold);
    new_window = new QWidget(nullptr);
    QVBoxLayout *tela = new QVBoxLayout();

    QLabel *time_label = new QLabel("Tempo de Busca: " + QString::number(((float)tempo)/CLOCKS_PER_SEC, 'g', 6) + " segundos");
    time_label->setFont(font);
    time_label->setAlignment(Qt::AlignCenter);

    QListWidget *lista = new QListWidget();
    lista->setFont(font);

    for(size_t i = 1; i < quantidades.size(); ++i) {
        if(quantidades[i])
            lista->addItem(QString::fromStdString("Número de pessoas com distância "
                                                  + to_string(i) + ": "
                                                  + to_string(quantidades[i])));
    }

    lista->addItem(QString::fromStdString("Número de pessoas sem contato: " + to_string(quantidades[0])));

    tela->addWidget(time_label);
    tela->addWidget(lista);
    new_window->setLayout(tela);
    new_window->setFixedSize(650, 330);
    new_window->show();

    QEventLoop loop;
    connect(this, SIGNAL(destroyed()), & loop, SLOT(quit()));
    loop.exec();
}

void window::dfs_connection() {

}
