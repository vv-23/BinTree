CC=x86_64-w64-mingw32-g++
CXXFLAGS= -g #-static -static-libgcc -static-libstdc++


submitdir = $(notdir $(CURDIR))
exe = $(submitdir)
builddir = build
objdir = $(builddir)/o
src = src
sources = $(wildcard $(src)/*.cpp)
objects = $(patsubst $(src)/%.cpp, $(objdir)/%.o, $(sources))


all: $(objects)
	$(CC) $(CXXFLAGS) $^ -o $(builddir)/$(exe)
$(objects): $(objdir)/%.o: $(src)/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
	
submit:
	mkdir $(submitdir)
	cp -r $(src)/ $(submitdir)/
	cp input.txt $(submitdir)/
	cp $(builddir)/$(exe) $(submitdir)/
	zip -r $(submitdir).zip $(submitdir)/
clean:
	rm -f build/o/*.o build/*.exe *.zip
	rm -r $(submitdir)
