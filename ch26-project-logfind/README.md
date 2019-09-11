# Project Logfind

Este capítulo nos dejará unas especificaciones para un proyecto bastante bagas
para que lo montemos como más nos guste. Una vez completado podremos ver un vídeo
con la solución del autor.

# Especificaciones

El proyecto se llamará `logfind` porque debe buscar en los archivos de log un texto.
Esta herramienta es una especialización de otra llamada `grep` pero designada solo
para los archivos de log del sistema. La idea es escribir:

`logfind zedshaw`

Y, buscará en todos los lugares comunes donde están guardados los archivos de log, 
y imprimirá todo fichero que tenga la palabra "zedshaw" dentro.

El `logfind` debe de tener estas funcionalidades básicas:

1. Esta herramienta acepta cualquier secuencia de palabras y asume que están
conectadaspor un "&" `and` lógico. Es decir, si escribimos `logfind zed shaw foo` buscará en
los ficheros de log y nos dirá en cuales aparece `zed`, `shaw` y `foo` al mismo tiempo.
2. Acepta un parámetro opcional `-o` que significa que los parámetros se deben 
conectar con un "|" `or` lógico.
3. Para cargar la lista de ficheros de log permitidos lo hará desde `~/.logfind`.
4. La lista de nombres de ficheros puede ser cualquiera que la función `glob` permita.
Referirse a `man 3 glob` para ver como funciona. Se sugiere empezar por una lista
de ficheros exactos y luego añadir la funcionalidad de `glob`
