#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    auto msg_pattern = "["\
            "%{if-debug}D%{endif}"\
            "%{if-warning}W%{endif}"\
            "%{if-critical}C%{endif}"\
            "%{if-fatal}F%{endif}]"\
            "%{file}:%{line} - %{message}";
    qSetMessagePattern(msg_pattern);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
