all:
	g++ lib/rnd-based-pattern.cc lib/pattern-based.cc lib/rnd-based.cc lib/generator-factory.cc lib/utils.cc lib/pf-based.cc lib/randomlib.cc lib/generator.cc lib/probability-factory.cc lib/fd-based.cc lib/probability.cc lib/game.cc lib/lottery.cc lib/read-result.cc lib/stats.cc main.cc -o fique-rico

debug:
	g++ -o0 -g3 -gdwarf-2 lib/rnd-based-pattern.cc lib/pattern-based.cc lib/rnd-based.cc lib/generator-factory.cc lib/utils.cc lib/pf-based.cc lib/randomlib.cc lib/generator.cc lib/probability-factory.cc lib/fd-based.cc lib/probability.cc lib/game.cc lib/lottery.cc lib/read-result.cc lib/stats.cc main.cc -o fique-rico
