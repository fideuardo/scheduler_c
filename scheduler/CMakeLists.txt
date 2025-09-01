# Define la biblioteca 'scheduler' a partir de sus archivos fuente
add_library(scheduler core/scheduler.c)

# Especifica los directorios de inclusión para el objetivo 'scheduler'.
# Al marcar el directorio 'core' como PUBLIC, cualquier objetivo que se enlace
# contra esta biblioteca (como nuestro ejecutable principal) tendrá automáticamente
# este directorio añadido a su ruta de inclusión.
target_include_directories(scheduler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/core)