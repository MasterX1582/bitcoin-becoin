from distutils.core import setup
setup(name='befspendfrom',
      version='1.0',
      description='Command-line utility for becoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@becoinfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
