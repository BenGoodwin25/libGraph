#Compiler to use
COMPILER=gcc
#Archiver for static lib
ARCHIVER=ar
#Possible Arguments
CFLAGS=-g -Wall
#Here insert the library you could need
LFLAGS=-lm

#Directories for main app
BINDIR=./bin
LIBDIR=./lib
OBJDIR=./obj
SRCDIR=./src
GRAPHSRCDIR=$(SRCDIR)/libgraph
LISTSRCDIR=$(SRCDIR)/liblist

#Defining main exec vars
EXEC=$(BINDIR)/menu
EXECSRC=$(wildcard $(SRCDIR)/*.c)
EXECOBJ=$(EXECSRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

#Defining libgraph vars
LIBGRAPH=$(LIBDIR)/libgraph.a
LIBGRAPHSRC=$(wildcard $(GRAPHSRCDIR)/*.c)
LIBGRAPHOBJ=$(LIBGRAPHSRC:$(GRAPHSRCDIR)/%.c=$(OBJDIR)/libgraph/%.o)

#Defining liblist vars
LIBLIST=$(LIBDIR)/liblist.a
LIBLISTSRC=$(wildcard $(LISTSRCDIR)/*.c)
LIBLISTOBJ=$(LIBLISTSRC:$(LISTSRCDIR)/%.c=$(OBJDIR)/liblist/%.o)

#Compile all targets
all: $(LIBDIR) $(OBJDIR) $(BINDIR) $(LIBGRAPH) $(LIBLIST) $(EXEC)

#Compile the main exec
$(EXEC): $(EXECOBJ)
	$(COMPILER) -static -o $@ $^ $(CFLAGS) $(LFLAGS) -L$(LIBDIR) -lgraph -llist

#Creating static graph lib
$(LIBGRAPH) : $(LIBGRAPHOBJ)
	$(ARCHIVER) rcs $@ $^

#Creating static list lib
$(LIBLIST) : $(LIBLISTOBJ)
	$(ARCHIVER) rcs $@ $^

#Rules for compiling main exec files
$(OBJDIR)/%.o : $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(COMPILER) -c $< $(CFLAGS) -o $(OBJDIR)/$*.o -I $(GRAPHSRCDIR) -I $(LISTSRCDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(COMPILER) -c $< $(CFLAGS) -o $(OBJDIR)/$*.o -I $(GRAPHSRCDIR) -I $(LISTSRCDIR)

#Rule for compiling lib graph files
$(OBJDIR)/libgraph/%.o : $(GRAPHSRCDIR)/%.c $(GRAPHSRCDIR)/%.h
	$(COMPILER) -c $< $(CFLAGS) -o $(OBJDIR)/libgraph/$*.o -I $(LISTSRCDIR)

#Rule for compiling lib list files
$(OBJDIR)/liblist/%.o : $(LISTSRCDIR)/%.c $(LISTSRCDIR)/%.h
	$(COMPILER) -c $< $(CFLAGS) -o $(OBJDIR)/liblist/$*.o

#Fonctionaly to come lather
#install:

#Creation of folders
$(OBJDIR) :
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/libgraph
	mkdir -p $(OBJDIR)/liblist

$(BINDIR) :
	mkdir -p $(BINDIR)

$(LIBDIR) :
	mkdir -p $(LIBDIR)

#Cleaning
clean:
	rm -r $(OBJDIR)

mrproper: clean
	rm -r $(BINDIR)
	rm -r $(LIBDIR)

#Just a debug command to show var value in make
print-%  : ; @echo $* = $($*)
