#include <QApplication>
#include "SettingsWindow.h"
#include "BackgroundWindow.h"
#include "BallSkinWindow.h"
#include "BricksSkinWindow.h"
#include "Arcanoid.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    Settings _settingsTest;
    SettingsWindow setWindowTest(_settingsTest);

    setWindowTest.show();

    return QApplication::exec();
}
