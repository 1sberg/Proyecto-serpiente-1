# Proyecto-serpiente-1

La arquitectura de un juego como la culebrita sigue un diseño sencillo y funcional, donde se estructuran elementos clave que representan los componentes del juego y sus interacciones. A continuación, se describe cómo podría diseñarse esta arquitectura en términos de programación:


---

1. Componentes Principales del Juego

El juego se puede dividir en los siguientes elementos clave:

1.1. Culebra

Atributos:

posición: Lista de coordenadas que representan cada segmento de la culebra.

dirección: Dirección actual (arriba, abajo, izquierda, derecha).

longitud: Número de segmentos de la culebra.


Métodos:

mover(): Actualiza la posición de la culebra según su dirección.

crecer(): Añade un segmento al final de la culebra.

chocar(): Verifica si la culebra colisionó consigo misma o con los límites.



1.2. Comida

Atributos:

posición: Coordenadas de la comida en el tablero.


Métodos:

generar_nueva_comida(): Coloca la comida en una posición aleatoria, asegurándose de que no esté ocupada por la culebra.



1.3. Tablero

Atributos:

ancho y alto: Dimensiones del tablero.

obstáculos: Opcionalmente, lista de coordenadas que representan barreras en el tablero.


Métodos:

dibujar(): Renderiza el estado actual del tablero (culebra, comida, y obstáculos).




---

2. Interacciones entre Componentes

El juego se basa en las interacciones dinámicas entre la culebra, la comida y el tablero.

2.1. Movimiento

En cada ciclo del juego:

La culebra se mueve en la dirección actual.

Si la cabeza de la culebra alcanza la posición de la comida, la culebra crece y se genera una nueva comida.



2.2. Detección de Colisiones

Se verifican tres tipos de colisiones:

Con los límites del tablero: Si la cabeza de la culebra está fuera de las dimensiones del tablero.

Con el cuerpo de la culebra: Si la cabeza coincide con alguna de las coordenadas de su cuerpo.

Con obstáculos (si aplican): Si la cabeza coincide con alguna coordenada de los obstáculos.




---

3. Ciclo del Juego

El juego se basa en un bucle principal que controla la lógica, actualizaciones y renderización.

3.1. Lógica Principal

1. Mover la culebra.


2. Comprobar si la culebra ha comido.


3. Detectar colisiones.


4. Actualizar el estado del juego.



3.2. Renderización

Actualizar visualmente el tablero para reflejar la nueva posición de la culebra y de la comida.
