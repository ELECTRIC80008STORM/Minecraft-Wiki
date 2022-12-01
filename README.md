# Minecraft Wiki Básica de Bloques
Este será una guía básica de las principales características de los bloques más comunes de Minecraft (basado en la versión Java Edition), esta listará diversos bloques y permitirá conocer sus propiedades y atributos, así como alguna otra información de utilidad.
 
## Utilidad:
El tener esta guía servirá de apoyo para los jugadores menos experimentados, pues les dará acceso a la información básica, y útil de saber de varios bloques comunes con los que te puedes encontrar en los primeros días de jugar el juego.
 
## Funcionalidad:
El programa utiliza clases para guardar la información de los bloques con facilidad, y para poder organizarla y darle un uso.
Al usuario se le permite escoger entre una serie de opciones, desde poder ver la lista de bloques actualmente guardados en la Wiki con su ID y nombre, u otra para poder ver información específica y detallada del bloque cuyo ID proporciones al programa (y esté guardado en la base de la Wiki).
Al usuario (manejador de la base de datos de la Wiki, admin) se le proporciona la capacidad de meter bloques a la Wiki.

## Correcciones:
UML (Nota: Entre varias cosas olvidé comentarlo en las asesorías): 
1. Sub-Competencia: Diseño clases sencillas completas (con todos los atributos y métodos requeridos). **Avance 2**

* Error Original: El becario me colocó un 0 en la calificación por no poner los constructores ni los tipos de datos que eran *void* en el diagrama de clases.

* Cambios Realizados: 
  * Se añadieron los tipos de datos que eran *void* a los métodos de las clases.
  * No se colocó constructores en el diagrama. (Esto porque en clase se había comentado que tanto poner los tipos de dato *void* y los constructores era algo debatido comúnmente y a criterio del programador, es decir, opcional).

Código: 
1. Sub-Competencia: Codificó métodos y atributos de clase correctamente. (constructores, getters, setters). **Avance 1**

* Error Original: No se habían creado setters para las clases que poseía en ese momento.

* Cambios Realizados: Se añadieron los setters para las clases “Bloque”, “Liquido” y “Mineral”.

* Líneas de código en donde se aprecia el cambio: 
  * En el archivo “Bloque.h” se puede apreciar la declaración de los setters entre las líneas 57 a 68. Y su definición entre las líneas 274 a 394.
  * En el archivo “Liquido.h” se puede apreciar la declaración de los setters entre las líneas 36 a 37. Y su definición entre las líneas 115 a 135.
  * En el archivo “Mineral.h” se puede apreciar la declaración de los setters entre las líneas 38 a 39. Y su definición entre las líneas 140 a 160.


2. Sub-Competencia: Compruebo el acceso a los atributos y métodos de la clase (encapsulamiento correcto, mandó a llamar los objetos de forma útil). **Avance 1**

* Error Original: Los objetos creados en ese momento no representaban alguna utilidad real.

* Cambios Realizados: Se sustituyeron los archivos de las clases pasadas por dos nuevos archivos “Liquido.h” que contiene la clase “Liquido” y el archivo “Mineral.h” que contiene la clase “Mineral”. Estas clases están más completas y representan bloques con características únicas o atributos predefinidos.

* Archivos de clases en donde se ve la corrección: Se puede apreciar el cambio en los archivos “Liquido.h” y “Mineral.h”.


## Registro de Cambios:
1. Se modificaron atributos y métodos de las clases ya existentes para que fueran más acorde al UML realizado con herencia.
2. Se eliminaron los archivos "Cristal.h" y "Madera.h".
3. Se añadieron los archivos de manera informal sobre los que se desea obtener retroalimentación en la asesoría. Estos todavía están en desarrollo. En estos cambios la clase "Bloque.h" y el Diagrama de Clases (UML) fueron sustituidos por archivos más actualizados.
4. Se eliminó el archivo "Testeo" que fué usado para la asesoría.
5. Se subió la versión más actualizada del archivo "Bloque.h", "Liquido.h", "Mineral.h" y "WikiData.h", así también como del "main.cpp". También se subió la versión más reciente del Diagrama de Clases UML.
6. Se subió la versión más reciente del "main.cpp", la cuál ya permite crear nuevos bloques (objetos / instancias).
7. Se añadieron más bloques a la base local de la app de la Wiki.
8. Se subió la versión final de todos los archivos a excepción del Diagrama de Clases de UML.
9. Corrección en el archivo "Mineral.h" en donde no se definia el valor de "transparente" como false para el primer constructor con parámetros.
10. Se actualizó el .README y una gran parte de la información que contenía, se eliminó el apartado de "Uso" y se añadió el apartado de Correcciones.
