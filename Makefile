LIBDIR := lib
OBJDIR := obj
OBJS := $(addprefix $(OBJDIR)/,deposit.o userbalance.o userbank.o userinterface.o \
	withdrawal.o main.o)
CPP := /usr/bin/g++
CPPOPTS = -std=c++11 -I$(LIBDIR)

$(OBJDIR)/%.o: $(LIBDIR)/%.cpp
	$(CPP) $(CPPOPTS) -c $< -o $@

$(OBJDIR)/main.o: main.cpp
	$(CPP) $(CPPOPTS) -c $< -o $@

bank_app: $(OBJS)
	$(CPP) $(CPPOPTS) $(OBJS) -o $@
	chmod +x $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR) back_app
