Algoritmo tetris
	Escribir '=== main.cpp ==='
	Escribir Panel_control cpp/h
	Escribir piezas cpp/h
	Mientras  NO salir Hacer
		Escribir ''
		Escribir '--- Despues de mover una pieza ---'
		Escribir '1. Mover pieza'
		Escribir '2. Verificar estado'
		Escribir '3. Salir'
		Leer tecla_presionada
		Según tecla_presionada Hacer
			1:
				Escribir "moverDerecha(), moverIzquierda(), moverAbajo()"
				Escribir "hay_colision(), fijar_pieza()"
			2:
				Escribir "eliminar_filas_llenas()"
				Escribir "juego_terminado(), destruir_tablero()"
			3:
				salir <- Verdadero
				Escribir "destruir_tablero"
			De Otro Modo:
				Escribir 'Acción no reconocida.'
		FinSegún
	FinMientras
FinAlgoritmo

// --- MÓDULOS DEL SISTEMA ---
Función Movimiento_CalcularColisiones
	Escribir '[movimiento.cpp] -> Calculando movimiento...'
	Escribir '   -> Realizando consulta posicional...'
	Piezas_BitwiseDeteccion()
FinFunción

Función FinJuego_EvaluarEstado
	Escribir '[fin_juego.cpp] -> Ejecutando limpieza de fila y Game Over...'
	Escribir '   -> Inspeccionando primera superposición de piezas...'
	Piezas_BitwiseDeteccion()
	Escribir '   -> Reestructurando punteros en el panel...'
	PanelControl_GestionarRenderizado()
FinFunción

Función Piezas_BitwiseDeteccion
	Escribir '[piezas.cpp] -> Ejecutando lógica Bitwise...'
	Escribir '   -> Verificando límites físicos y grabando estado...'
	PanelControl_GestionarRenderizado()
FinFunción

Función PanelControl_GestionarRenderizado
	Escribir '[panel_control.cpp] -> Gestionando datos del tablero...'
	Escribir '   -> Leyendo bits del objeto para renderizar...'
FinFunción

Función PanelControl_ReservarDimensiones
	Escribir '[panel_control.cpp] -> Reservando dimensiones del tablero...'
FinFunción

Función Piezas_ReclamarInstancia
	Escribir '[piezas.cpp] -> Reclamando nueva instancia de la pieza...'
FinFunción
