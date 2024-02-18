CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -Werror

# Путь к исходным файлам
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Список заголовочных файлов
INCLUDES = $(wildcard $(INCDIR)/*.hpp)

# Список исходных файлов
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Список объектных файлов
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Название исполняемого файла
EXECUTABLE = test

# Правило по умолчанию для сборки исполняемого файла
all: $(BUILDDIR)/$(EXECUTABLE)

# Цель для сборки исполняемого файла
$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Правило для компиляции каждого исходного файла в объектный
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDES)
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) $< -o $@

# Цель для очистки сгенерированных файлов
clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean