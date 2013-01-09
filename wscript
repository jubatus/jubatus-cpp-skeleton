def options(opt):
  opt.load('compiler_cxx')

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
  conf.load('compiler_cxx')
  conf.check_cxx(lib = 'msgpack')
  conf.check_cxx(lib = 'jubatus_mpio')
  conf.check_cxx(lib = 'jubatus_msgpack-rpc')

def build(bld):
  bld.program(
    source = 'client.cpp',
    target = 'client',
    use = ['MSGPACK', 'JUBATUS_MPIO', 'JUBATUS_MSGPACK-RPC'],
    )
