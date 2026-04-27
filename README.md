# Sistema de Riego Automático

Sistema de riego automático para Arduino Uno que activa una bomba de agua o electroválvula cada 8 horas durante 1 hora.

## Funcionamiento

- Al encender el Arduino, el riego se activa inmediatamente durante 1 hora.
- Tras finalizar, espera 8 horas y vuelve a regar 1 hora, en ciclo continuo.
- El estado del riego se reporta por el monitor serial a 9600 baud.

## Hardware

| Componente | Conexión |
|---|---|
| Módulo relé / bomba de agua | Pin digital 7 |

### Esquema de conexión

```
Arduino Uno Pin 7 ──► Módulo Relé ──► Bomba de agua / Electroválvula
```

## Configuración

Las constantes de tiempo se pueden ajustar en `src/main.cpp`:

```cpp
const unsigned long RIEGO_DURACION  = 1UL * 60 * 60 * 1000;  // 1 hora
const unsigned long RIEGO_INTERVALO = 8UL * 60 * 60 * 1000;  // 8 horas
```

## Compilación

El proyecto usa [PlatformIO](https://platformio.org/). Para compilar y subir al Arduino:

```bash
pio run -t upload
```

Para abrir el monitor serial:

```bash
pio device monitor
```

## Estructura del proyecto

```
├── platformio.ini      # Configuración de PlatformIO
├── src/
│   └── main.cpp        # Programa principal
├── test/
│   └── test_main.cpp   # Tests unitarios
├── include/
└── lib/
```

## Licencia

Este proyecto es de uso libre.
