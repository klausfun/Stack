CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -Werror
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Исходные файлы
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Название исполняемого файла
EXECUTABLE = cpu_executable

# Цель по умолчанию
all: $(BUILDDIR)/$(EXECUTABLE)

# Сборка исполняемого файла
$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Компиляция исходных файлов
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -I$(INCDIR) $< -o $@

# Очистка собранных файлов
clean:
	rm -rf $(BUILDDIR)