# Days of Survival — Beta web 0.1

Esta rama propone una beta visual en navegador del juego de aventuras en C++.

## Probar la beta
El archivo `docs/index.html` contiene toda la interfaz y la historia en un único HTML. Descárgalo y ábrelo en un navegador moderno para jugar sin ejecutar archivos .exe.

**Incluye:** menú principal, animación de texto, decisiones ramificadas, 21 escenas, finales, guardado local y un formulario para copiar comentarios. La historia original sigue en inglés. No se envían opiniones a un servidor.

## Publicar con GitHub Pages (cuando se acepte el cambio)
1. Fusionar la solicitud de cambios con `main`.
2. En **Settings → Pages**, configurar **Deploy from a branch**, seleccionar `main` y la carpeta `/docs`.
3. Guardar y esperar a que GitHub indique la URL publicada.
4. Probar la versión publicada antes de compartirla.

El juego no se publica automáticamente por crear esta rama o pull request.

## Próximos pasos
- Incorporar el refactor completo del motor C++, el exportador de escenas, las pruebas y el código de la interfaz nativa raylib que fueron preparados aparte.
- Verificar el ejecutable nativo de Windows; aún no se ha compilado en Windows en esta propuesta.
- Ajustar la continuidad narrativa y recoger sugerencias.

Esta PR solo incluye la versión web ya probada y estas notas, para no sustituir el proyecto de consola original.
