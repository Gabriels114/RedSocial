//
// Created by gabriels on 26/11/24.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RedSocial.h"

RedSocial red;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    red.cargarUsuariosPredefinidos();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_registerButton_clicked() {
    QString nombre = ui->registerLineEdit->text();
    red.registrarUsuario(nombre.toStdString());
}

void MainWindow::on_loginButton_clicked() {
    QString nombre = ui->loginLineEdit->text();
    red.iniciarSesion(nombre.toStdString());
}

void MainWindow::on_logoutButton_clicked() {
    red.cerrarSesion();
}

void MainWindow::on_addFriendButton_clicked() {
    QString nombreAmigo = ui->addFriendLineEdit->text();
    red.anadirAmigo(nombreAmigo.toStdString());
}

void MainWindow::on_postMessageButton_clicked() {
    QString mensaje = ui->postMessageLineEdit->text();
    red.publicarMensaje(mensaje.toStdString());
}

void MainWindow::on_showMessagesButton_clicked() {
    red.mostrarPublicaciones();
}

void MainWindow::on_searchUserButton_clicked() {
    QString nombre = ui->searchUserLineEdit->text();
    red.buscarUsuario(nombre.toStdString());
}