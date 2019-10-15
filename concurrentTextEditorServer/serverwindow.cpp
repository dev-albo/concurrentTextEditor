#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QMessageBox>
#include "server.h"

ServerWindow::ServerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWindow),
    m_server(new Server(this))
{
    ui->setupUi(this);
    connect(ui->startStopButton, &QPushButton::clicked, this, &ServerWindow::toggleStartServer);
    connect(m_server, &Server::logMessage, this, &ServerWindow::logMessage);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::toggleStartServer() {
    if(m_server->isListening()) {
        m_server->stopServer();
        ui->startStopButton->setText(tr("Start Server"));
        logMessage("Server Stopped");
    } else {
        if(!m_server->listen(QHostAddress::Any, 0)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to connect"));
            return;
        }
        logMessage("Server Started");
        ui->startStopButton->setText(tr("Stop Server"));
    }
}

void ServerWindow::logMessage(const QString &msg)  {
    ui->logEditor->appendPlainText(msg + '\n');
}
