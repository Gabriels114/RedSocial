#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();
    void on_logoutButton_clicked();
    void on_addFriendButton_clicked();
    void on_postMessageButton_clicked();
    void on_showMessagesButton_clicked();
    void on_searchUserButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H