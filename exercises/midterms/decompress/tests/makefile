include $(GL_LIB_PATH)/makefile_base

tests: tests.c
	$(CC) $(CFLAGS) -c $< -o $(OUTDIR)/$@.o 

run_tests: $(OUTDIR)/decompress.o tests
	OUT_DIR=$(OUTDIR) make -C $(GL_LIB_PATH)/lunit lunit
	$(LD) $(LDFLAGS) $(OUTDIR)/tests.o $(OUTDIR)/decompress.o $(OUTDIR)/lunit.o $(OUTDIR)/cmp.o $(OUTDIR)/list.o -o $(OUTDIR)/$@
