#=========================
# Inlämnings_uppgift_del5
# kalkylatorn
# Kursprogram i C++
# Handledare: Gladyz Pabon
# Datum:  2018-03-09
# @auktor: Amer Ahmed
#=========================
QT  += core gui

 greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app

CONFIG += c++11

# Följande definiera gör att kompilator avger varningar om man använder
# någon egenskap av Qt som har markerats som avlägsnad (de exakta varningarna
# beror på  kompilator). Vänligen se dokumentationen av
# avstängt API för att veta hur det portar dess kod bort från den
DEFINES += QT_DEPRECATED_WARNINGS

# Det kan också göra att den kod inte kompilerar om man använder föråldrade API: er.
# För att göra det, kommentera inte följande rad.
# Man kan också välja att inaktivera avlägsna API: er bara upp till en viss version av Qt.
#DEFINES + = QT_DISABLE_DEPRECATED_BEFORE = 0x060000 # avaktiverar alla API: er som avskrivits före Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# kalkylatorn icon
RC_ICONS = Calculator.ico

DISTFILES += \
    README.md
