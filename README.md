# Silver-Chariot-Robot
Repositorio hecho para mostrar el proceso de armado, programación y progreso de el robot del equipo DATO del IPT Don Bosco

Informe de progreso de armado y preparación del robot.

-Ruedas delanteras para el eje de dirección.

![image](https://github.com/Himot-03/Silver-Chariot-Robot/assets/74327576/1984601c-bb64-4e31-b8ba-782bf46d22ad)

Rruedas del eje de dirección atornilladas a un chasis y el eje de tracción con un motor de 12V conectado con engranajes al eje.

![image](https://github.com/Himot-03/Silver-Chariot-Robot/assets/74327576/cc768d9f-fdde-40bb-a029-79af96d88c83)

![image](https://github.com/Himot-03/Silver-Chariot-Robot/assets/74327576/b4f35366-8e56-43d0-a44c-420ccc448a41)

-Eje de dirección

![image](https://github.com/Himot-03/Silver-Chariot-Robot/assets/74327576/9f4ba3d4-52d5-48bb-8235-8df50ec9cd1b)

-Funcionamiento de ambos ejes con una bateria de 9V.

https://youtube.com/shorts/5usiPg76XBs?feature=share

-Funcionamiento del eje de dirección programado con un controlador de Motores L293D y una placa de arduino.

https://youtu.be/F1HKEL-cy-s

-Para el cerebro del robor hemos decidido usar una placa de Arduino MEGA y un controlador de Motores L298N para el motor de tracción, pegados sobre el chasis del Robot elevandos.

![Imagen de WhatsApp 2023-07-29 a las 22 45 01](https://github.com/Himot-03/Silver-Chariot-Robot/assets/74327576/745b1fcb-274f-4710-9774-fc287d5c9146)

-Funcionamiento de Ambos ejes para el avance del Robot programado con una placa Arduino MEGA alimentada por un power bank via USB y un controlador de Motores L298N alimentado por una bateria 9V.

https://youtube.com/shorts/eCfFVeuqVgE?feature=share

-A función de detector de proximidad, se ha colocado un sensor ultrasónico sobre un motor microservo en la parte frontal del Robot.

https://youtu.be/D-9Sd_0ZiU8

-Se ha colocado una MiniProtoboard delante del Arduino MEGA para conectar Jumpers de corriente y una pantalla OLED de 128x64.

![image](https://github.com/Himot-03/Silver-Chariot-Robot/assets/74327576/9865d0ed-47d3-4a4d-9e25-fc649162dac9)

-Se le ha colocado un sensor de color para la deteccion de las señales de tránsito en la pista.

![image](https://github.com/Himot-03/Silver-Chariot-Robot/assets/74327576/3c37ccf4-7e8b-4b86-83ea-fe1c53c761be).

-Se ha programado el sensor de proximidad para detectar objetos cercanos y imprimir la distancia de estos en la pantalla del robot, si la distancia impresa es menor a 40cm, se activa el estado de danger.
-El sensor ultrasónico envia una onda y esta rebota en el obstáculo y regresa y el sensor la recibe, dandonos la duración del viaje de la onda, se multiplica la duración por la velocidad del sonido y se divide entre 2 para calcular la distancia del objeto con el robot.

https://youtu.be/_brEhWQEPqY

-Funcionamiento del estado de danger para detener el robot frente a un obstáculo y evitar una colisión.

https://youtube.com/shorts/nfkTEhl7zng?feature=share

-Se ha reemplazado el sensor de color por uno mas efectivo para la detección de los colores.

![image](https://github.com/Himot-03/Silver-Chariot-Robot/assets/74327576/356a0544-2abc-462c-857a-099ce3db1a24)




