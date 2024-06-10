Ejercicios POO

Carpeta Ejercicio1:
- Crear un primer programa que muestre por la consola de QtCreator 10 números aleatorios en el intervalo [ 2, 20 ]
- Cada vez que se ejecute el programa, los números deberán ser aleatorios y distintos en cada ejecución.

Carpeta Ejercicio2:
- Crear una librería en C++ y compilarla como un archivo DLL 8o similar en otros sistemas operativos). Programar en la librería una función que imprima un mensaje simple, como "Hola, desde la biblioteca".
- Crear un programa principal en C++ que utilice esta librería. Hacer referencia (o linkear) a la librería de manera dinámica.
- Incluir la ruta al archivo DLL en la variable de entorno PATH.
- En el programa principal, cargar la librería, invocar a la función y mostrar el mensaje.

Carpeta Ejericio3:
- Elija un nombre para su propio espacio de nombres para todo lo que se haga en este asignatura
- Luego de elegido el nombre para su namespace, defina una función dentro de ese namespace para devolver el número de versión junto con la fecha de la última actualización de la biblioteca

Carpeta Ejercicio4:
- Crear un std::vector para contener int
- Cargar 30 valores pseudo aleatorios entre 1 y 15
- Publicar la moda

Carpeta Ejercicio5:
- Crear un std::vector para contener objetos de la clase std::string
- Cargar 5 expresiones idiomáticas, como por ejemplo: pan comido
- Publicar por consola ordenado alfabéticamente

Carpeta Ejercicio6:
- En un Empty qmake Project
- Crear una nueva clase (que no sea Persona, ni Cliente, ni Poste). Invente una clase.
- Agregar uno o más constructores, agregar sus métodos y sus atributos
- Crear algunos objetos de esta clase en la función main

Carpeta Ejercicio7:
- Empty qmake Project
- Utilizar la clase creada en el ejercicio anterior para crear objetos y almacenarlos en un std::vector
- ¿Se pueden ordenar? Qué estrategia utilizaría para ordenarlos de menor a mayor

Carpeta Ejercicio8:
- En un Empty qmake Project
- Crear una función genérica que imprima por consola una descripción de cualquier objeto.
- El mensaje puede ser algo así: "Persona con nombre Lucrecia", "Poste con altura de 8 metros y 15 cm de diámetro".
- Probar esta función en main utilizando dos objetos de la clase Persona y dos objetos de la clase Poste.
- Incluir todo el código fuente en el archivo main.cpp.
- Pedirle al chat el código, interpretarlo y hacerlo funcionar.

Carpeta Ejercicio9:
- En un Empty qmake Project
- Crear una función genérica que imprima por consola sus valores ordenados
- Es decir, se le pasa un array con sus valores en cualquier orden, y la función genérica los imprime ordenados
- Que el prototipo sea: template < class T > void imprimir( T * v, int cantidad, bool mayor_a_menor );
- Utilizar el método de ordenamiento por inserción
- Probar esta función en main utilizando dos arrays (int y float) y ordenar de mayor a menor y el otro al revés.

Carpeta Ejercicio10:
- En un Empty qmake Project
- Crear una clase Jugador con atributos int velocidad, int fuerza y std::string nombre
- Usar constructor inicializando de la manera recomendada la velocidad en 0, fuerza en 0 y nombre "sin nombre"
- Crear los métodos setter y getter para setear y obtener los valores de los atributos
- Incluir el destructor
- En la función main crear un std::vector< Jugador > e insertar 10 jugadores distintos
- Por último, publicar los datos de cada uno de los jugadores con std::cout

Carpeta Ejercicio11:
- En un Empty qmake Project
- En la función main crear un objeto de la clase QLabel, uno de QWidget, uno de QPushButton y uno de QLineEdit
- Invocar al método show() de cada uno de estos 4 objetos
- Notar que cada objeto se muestra independiente

Carpeta Ejercicio12:
- En un Empty qmake Project
- En la función main crear un objeto de la clase QLabel y pegarle en el mismo objeto QLabel una imagen de alta resolución.
- Que la imagen se obtenga desde un archivo JPG del disco duro
- Mostrar el QLabel de forma maximizada y que la imagen no se deforme.
- Al cabo de 3 segundos, el QLabel y la aplicación se deberá cerrar

Carpeta Ejercicio13:
- Punto de partida: Usar el código del ejemplo del control de volumen
- Cuando el valor del QSlider se modifique, colocar como título de la ventana el mismo valor que tiene el QSlider.

Carpeta Ejercicio14
- Diseñar un login con QGridLayout.
- Usar asteriscos para la clave.
- Detectar enter para simular la pulsación del botón.
- Definir la clase Formulario que será un QWidget
- Formulario tendrá QLabels y QLineEdits para Legajo, Nombre y Apellido, y un QPushButton
- Si la clave ingresada es admin:1111, se cierra Login y se muestra Formulario
- Si se ingresa otra clave se borrará el texto del QLineEdit de la clave.

Implementaciones al ejercicio:
- Publicar en la ventana de Login, la temperatura actual en la Ciudad de Córdoba. Usar alguna API disponible.
- Agregar un método en Login que permita mostrar u ocultar la información de la temperatura.
- Además que la ventana de Login tenga como background una imagen descargada de interner, centrada y adaptada en tamaño, sin deformar su aspecto y - que permita al usuario que modifique el tamaño del Login y que se siga viendo correctamente la imagen.
- Agregar un método en Login que permita indicar la URL de la imagen que se mostrará en el background. En caso que nunca se invoque a este método, ninguna imagen se mostrará.
- Incorporar la validación de usuarios con QSLite.
- Todo lo que se haga con la base de datos, que se encuentre en la clase AdminDB
- Implementar en AdminDB el uso de MD5 para las claves de los usuarios.
- Acondicionar para que el método utilizado sea el siguiente:
- Definir en Login una signal que se emita cada vez que un usuario se loguee exitosamente. La signal debe emitir el nombre de usuario.

Carpeta Ejercicio15:

Carpeta Ejercicio16:
- Registrar en MongoDB algunos usuarios (nombre, apellido, usuario, clave)
- Tener disponible un endpoint con FastAPI para validar usuarios.

Carpeta Ejercicio17:
- Diseñar un login que cargue como fondo, una imagen descargada de internet
- Cuando un usuario sea válido, que se abra en full screen otra ventana (definida en la clase Ventana) y que tenga otra imagen descargada de internet en su interior, abarcando toda la ventana.
- Esta ventana no deberá abrirse hasta tanto se haya descargado la imagen.
- La imagen no se debe deformar al visualizarse.

Carpeta Ejercicio18:
- Utilizar un proyecto con un login cualquiera que valide admin:1234
- Cuando el usuario es válido, abrir una nueva ventana que tenga un QTextEdit que permita mostrar código HTML.
- Esta ventana deberá tener un QLineEdit que permita ingresar una URL
- Cuando se pulse Enter, se deberá buscar el html de la URL escrita y se deberá publicar en el QTextEdit.

Carpeta Ejercicio19:
- Crear una clase Pintura que herede de QWidget y que permita dibujar a mano alzada con el mouse.
- Con el scroll permitirá ampliar y disminuir el tamaño del trazo del pincel.
- Con las teclas R, G y B se cambia el color del pincel.
- Con Escape se borra todo lo que esté dibujado.

Carpeta Ejercicio20:
- Crear un proyecto Qt Widget Application con un QWidget que sea la clase Ventana
- Crear una clase Boton que hereda de QWidget
- Redefinir paintEvent en Boton y usar fillRect para dibujarlo de algún color
- Usar QtDesigner para Ventana y Boton. Es decir, Designer Form Class
- Definir la enumeración en Boton
- Abrir el designer de Ventana y agregar 5 botones (objetos de la clase Boton). Promocionarlos
- Usar para Ventana grid layout, usar espaciadores y usar todos los recursos posibles del QtDesigner
- Dibujar un fondo agradable con paintEvent y drawImage
- Que Boton tenga la señal signal_clic()
![alt text](image.png)

Carpeta Ejercicio21:
- Definir dos QWidgets (una clase Login y una clase Ventana).
- El Login validará al usuario contra una base SQLite
- La Ventana sólo mostrará un QPushButton para "Volver" al login.
- Crear solamente un objeto de Ventana y uno solo de Login.
- Si sucede un problema en la compilación, analizar los motivos (respetar el enunciado).
- Solucionar ese problema y ver la alternativa de hacerlo con Manager.

Carpeta Ejercicio22:
- Crear una clase base llamada Instrumento y las clases derivadas Guitarra, Bateria y Teclado.
- La clase base tiene una función virtual pura llamada sonar().
- Defina una función virtual verlo() que publique la marca del instrumento. Por defecto todos los instrumentos son de la marca Yamaha.
- Utilice en la función main() un std::vector para almacenar punteros a objetos del tipo Instrumento. Instancie 5 objetos y agréguelos al std::vector.
- Publique la marca de cada instrumento recorriendo el vector.
- En las clases derivadas agregue los datos miembro "int cuerdas", "int teclas" e "int tambores" según corresponda. Por defecto, guitarra con 6 cuerdas, teclado con 61 teclas y batería con 5 tambores.
- Haga que la clase Teclado tenga herencia múltiple, heredando además de una nueva clase Electrico. Todos los equipos del tipo "Electrico" tienen por defecto un voltaje de 220 volts. Esta clase deberá tener un destructor que al destruirse publique la leyenda "Desenchufado".
- Al llamar a la función sonar(), se deberá publicar "Guitarra suena...", "Teclado suena..." o "Batería suena..." según corresponda.
- Incluya los métodos get y set que crea convenientes.

Carpeta Ejercicio23:
- Reutilizar el código fuente de cualquier otro ejericio y utilizar herencia múltiple, inline y friend.
- Implementar herencia múltiple, inline y friend cuando sea beneficioso hacerlo.
( Se utilizo el codigo del ejercicio 22 para realizar este punto )

Carpeta Ejercicio24:
- Crear un parser que pueda analizar cualquier html en busca de todas las URLs que encuentre
- Crear una GUI que permita al usuario ingresar un sitio web en un QLineEdit
- Que descargue en archivos todos los recursos de dicho sitio web
- Es decir, que busque en el html las imágenes, los css, los javascript y los descargue en archivos
- Que le permita al usuario indicar en qué directorio descargar los archivos
- También agregar un botón que upermita elegir un archivo de imagen del disco con QFileDialog y que la dibuje en pantalla con paintEvent.

Carpeta LoginApp (Ejercicio 25):
- Construir un nuevo proyecto que tenga un Login independiente, es decir, que no dependa de otra clase GUI.
- El Login tenga un QLabel que funciona como botón que sea para registrar un nuevo usuario.
- Cuando se presiona el QLabel que funciona como botón, se abrirá una ventana para dar de alta un usuario.
- Usar SQLite con AdminDB como singleton.
- Cuando un usuario válido ingresa correctamente se mostrará otra ventana que visualizará todos los usuarios cargados en la base.
- Para la visualización de los usuarios se puede usar QTreeWidget. Agregar la funcionalidad para que en esta misma ventana se puedan editar los campos como si fuera una planilla tipo excel.
- Seguir las recomendaciones que se comentaron durante el dictado de clases para construir las clases.

Carpeta admindb:
- En esta carpeta, se encuentra una conexion basica a la base de datos, la cual fue desarrollada para practica.

Carpetas Simulacros A,B,C,D:
- En estas carpetas se encuentran los ejercicios de simulacro para practicar para el segundo parcial. 