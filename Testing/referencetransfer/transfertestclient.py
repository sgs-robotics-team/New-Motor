import transfertestserver

print("a %d" % transfertestserver.globalval)
transfertestserver.changeGlobalVal(12345)
transfertestserver.globalval=12345
print("b %d" % transfertestserver.globalval)
