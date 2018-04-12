# homework1
Primo Homework 

---COMPILAZIONE---
1. Spostarsi nella Directory catkin_ws
2. Eseguire il comando: catkin_make install (creazione dei messaggi)
3. Eseguire il comando: catkin_make --pkg homework1 (compilazione programmi)


---ESECUZIONE---
METODO 1 (launchfile)
1. Spostarsi nella Directory launch (catkin_ws/src/homework1/launch)
2. Eseguire il comando: roslaunch homework1 homework1_launch.launch

METODO2 (singoli file)
1. Aprire 4 terminali e spostarsi in tutti nella Directory catkin_ws
2. Nel primo terminale digitare il comando roscore
3. Nel secondo terminale digitare il comando rosrun homework1 selector
4. Nel terzo temrinale digitare il comando rosrun homework1 printer
5. Nel terzo terminale digitare il comando rosrun homework1 generator


---FUNZIONAMENTO---
1. NODO SELECTOR: questo nodo serve per selezionare le modalità di visualizzazione (tutto, nome, età, corso, oppure terminare) e permette di inserire un carattere a scelta fra i seguenti
2. NODO GENERATOR: questo nodo genera un messaggio al secondo contenente un nome, un'età e un corso di laurea in modo casuale.
3. NODO PRINTER: questo nodo stampa a video i messaggi ricevuti da GENERATOR secondo le modalità ricevute da SELECTOR.


---NOTE---

Per terminare l'esecuzione del nodo SELECTOR occorre obbligatoriamnte inserire il
carattere 'q' poichè non terminerebbe con ctrl+C.
Il nodo PRINTER inizialmente non stampa niente perchè aspetta di ricevere almeno
il primo messaggio da SELECTOR.
Con il launchfile i programmi verranno eseguiti su XTerm
