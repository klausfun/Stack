CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -Werror
SRCDIR = .
INCDIR = ../include
BUILDDIR = build

# Исходные файлы тестов
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Название исполняемого файла тестов
EXECUTABLE = test

# Цель по умолчанию
all: $(BUILDDIR)/$(EXECUTABLE)

# Сборка исполняемого файла тестов
$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Компиляция исходных файлов тестов
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -I$(INCDIR) $< -o $@

# Очистка собранных файлов
clean:
	rm -rf $(BUILDDIR)