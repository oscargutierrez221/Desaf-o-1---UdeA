Algoritmo TetrisBits
	Definir ancho, alto, posicionX, posicionY Como Entero
	Definir gameOver, piezaFijada, colision Como Logico
	Definir accion Como Caracter
	
	Escribir "Ingrese ancho del tablero (múltiplo de 8, min 8): "
	Leer ancho
	Escribir "Ingrese alto del tablero (min 8): "
	Leer alto
	
	Si ancho < 8 O ancho MOD 8 <> 0 O alto < 8 Entonces
		Escribir "Dimensiones invalidas. El ancho debe ser múltiplo de 8."
	Sino
		gameOver <- Falso
		Mientras No gameOver Hacer
			posicionX <- trunc(ancho / 2) - 2
			posicionY <- 0
			piezaFijada <- Falso
			colision <- Falso
			
			Mientras No piezaFijada Hacer
				Escribir "Accion: [A]Izq [D]Der [S]Bajar [W]Rotar [Q]Salir:"
				Leer accion
				Segun accion Hacer
					"A", "a": posicionX <- posicionX - 1
					"D", "d": posicionX <- posicionX + 1
					"W", "w": Escribir "Rotando..."
					"S", "s": 
						posicionY <- posicionY + 1
						piezaFijada <- Verdadero 
					"Q", "q":
						gameOver <- Verdadero
						piezaFijada <- Verdadero
				FinSegun
				
				Si No piezaFijada Y accion <> "S" Y accion <> "s" Entonces
					posicionY <- posicionY + 1
				FinSi
			FinMientras
		FinMientras
		Escribir "GAME OVER"
	FinSi
FinAlgoritmo