# Indicamos que es una aplicación de Qt
QT += core gui network

# Especificamos la versión mínima de Qt requerida
QT_MIN_VERSION = 5.15

# Nombre del proyecto y el idioma estándar de C++
TARGET = html_downloader
TEMPLATE = app
CONFIG += c++17

# Listamos los archivos de código fuente
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    htmlparser.cpp

# Listamos los archivos de encabezado
HEADERS += \
    mainwindow.h \
    htmlparser.h

# Recursos (si tienes algún archivo .qrc, descoméntalo y añádelo aquí)
# RESOURCES += \
#     resources.qrc

# Habilitar el manejo de eventos de pintado personalizados
DEFINES += QT_NO_KEYWORDS

# Habilitar el uso de espacios de nombre de Qt para evitar conflictos de nombres
CONFIG += c++11
