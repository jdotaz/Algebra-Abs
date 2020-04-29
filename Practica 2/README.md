# Práctica de laboratorio 2

_Realizado por Juan Diego Obando Zúñiga._
_Práctica sobre el cifrado de Vigenere, todos los ejercicios estan completos y comprobados, excepto el 3b._


## Observaciones 🚀

### Ejercicio 3b 📋

* Explicación ambigua sobre la implementacion de los alfabetos ASCII y HEX.

### Ejercicio 3d 🔧

* Implementación el criptoanalisis Kasiski como código(sirve con textos largos con clave de 4 digitos).
* El error de que solo decifraba claves de 4 dígitos se debió a que el número 4 fue usado en un función como constante.
* Kasiski corregido y estable, en una carpeta aparte(Kasiski corregido).

### Otras 📙

* Ya que el alfabeto que manejamos incluye el " "(espacio) si un mensaje después de ser cifrado inicia o termina en este carácter, corre el riesgo de ser obviado por el usuario y al decifrarlo se perderia, en el mejor de lo casos, el ultimo elemento o, en el peor de los casos, no seria posible decifrar este mensaje ya que al faltar el primer elemento todos caracteres estarian corridos un espacio a la izquierda.
