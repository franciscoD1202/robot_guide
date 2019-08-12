// Teleoperación del robot

Para la teleoperación del robot se debe tener una conexión activa con el robot.

Para conectarse con el robot, se pueden usar los ejecutables .launch de creación o navegación, ó siguiendo los siguientes pasos.

1. Inicializar el espacio de trabajo de ros:
	. catkin_ws/devel/setup.bash 

2. Ejecutar una terminal con el comando:
	roscore

3. Ejecutar en una segunda terminal con el espacio de trabajo inicializado
	rosrun rosaria RosAria _port:=157.253.173.241:8101 

4. Ejecutar en otra terminal el siguiente comando:
	rosrun robot_control robot_control

De esta manera se puede teleoperar el robot con las teclas W/A/S/D

// Creación de Mapas

Para la creación de mapas se deben seguir los siguientes pasos:

1. Ubicar el robot en un punto inicial marcado. Este sera el origen (punto [ 0.0, 0.0, 0.0]) del mapa. 

2. Encender el robot. Presionar el boton rojo que se encuentra ubicado en la parte lateral para permitir la comunicación por medio de la red inalambrica. 

3. Ejecutar la terminal/terminator con 2 (DOS) pestañas. 

4. Ejecutar el comando:
	. catkin_ws/devel/setup.bash 
Este comando ubica el espacio de trabajo.

5. Ejecutar en una pestaña de comandos:
	roslaunch robot_control slam_p3dx_robot.launch 
Este comando inicia la conexión con el robot y gmapping para la creación del mapa. 

6. Ejecutar en la segunda pestaña :
	rosrun robot_control robot_control 
Este permite hacer la teleoperación del robot utilizando las teclas W/A/S/D

7. Una vez terminado el proceso de construcción del mapa NO CERRAR las terminales. 

SE DEBE EJECUTAR  en la carpeta que se desee guardar el mapa generado: 

rosrun map_server map_saver -f [nombre]

8. Cerrar todas las ventanas y apagar el robot al terminal.

/** RECOMENDACIÓN: Utilizar una tercera pestaña para visualizar el nivel de bateria del robot. (rostopic eo /RosAria/battery_voltage) Cuando este sea inferior a 11.5 detener el proceso teniendo en cuenta que desde este punto las mediciones pueden tener problemas. **/


// Navegación Autonoma 


1. Ubicar el robot en la marca amarilla que se encuentra en la entrada del laboratorio con el robot viendo hacia el laboratorio. 

2. Encender el robot. Presionar el boton rojo que se encuentra ubicado en la parte lateral para permitir la comunicación por medio de la red inalambrica. 

3.  Ejecutar el comando:
	. catkin_ws/src/robot_control/robot_guide.sh

/** RECOMENDACIÓN: Utilizar una tercera pestaña para visualizar el nivel de bateria del robot. (rostopic eo /RosAria/battery_voltage) Cuando este sea inferior a 11.5 detener el proceso teniendo en cuenta que desde este punto las mediciones pueden tener problemas. **/

/** RECOMENDACIÓN: En caso de que el robot se detenga y no se pueda recuperar, se puede recuperar haciendo la teleoperación para hacer la "limpieza" de la grilla de ocupación **/
