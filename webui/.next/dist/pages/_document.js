'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _getPrototypeOf = require('next/node_modules/babel-runtime/core-js/object/get-prototype-of');

var _getPrototypeOf2 = _interopRequireDefault(_getPrototypeOf);

var _classCallCheck2 = require('next/node_modules/babel-runtime/helpers/classCallCheck');

var _classCallCheck3 = _interopRequireDefault(_classCallCheck2);

var _createClass2 = require('next/node_modules/babel-runtime/helpers/createClass');

var _createClass3 = _interopRequireDefault(_createClass2);

var _possibleConstructorReturn2 = require('next/node_modules/babel-runtime/helpers/possibleConstructorReturn');

var _possibleConstructorReturn3 = _interopRequireDefault(_possibleConstructorReturn2);

var _inherits2 = require('next/node_modules/babel-runtime/helpers/inherits');

var _inherits3 = _interopRequireDefault(_inherits2);

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _document = require('next/dist/server/document.js');

var _document2 = _interopRequireDefault(_document);

var _styledComponents = require('styled-components');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var _jsxFileName = '/home/5gTest/open5gs-v2.2.6/webui/pages/_document.js?entry';


var description = 'an implementation of 3GPP EPC(MME, SGW, PGW, HSS)';

var MyDocument = function (_Document) {
  (0, _inherits3.default)(MyDocument, _Document);

  function MyDocument() {
    (0, _classCallCheck3.default)(this, MyDocument);

    return (0, _possibleConstructorReturn3.default)(this, (MyDocument.__proto__ || (0, _getPrototypeOf2.default)(MyDocument)).apply(this, arguments));
  }

  (0, _createClass3.default)(MyDocument, [{
    key: 'render',
    value: function render() {
      var sheet = new _styledComponents.ServerStyleSheet();
      var main = sheet.collectStyles(_react2.default.createElement(_document.Main, {
        __source: {
          fileName: _jsxFileName,
          lineNumber: 9
        }
      }));
      var styleTags = sheet.getStyleElement();
      return _react2.default.createElement('html', {
        __source: {
          fileName: _jsxFileName,
          lineNumber: 12
        }
      }, _react2.default.createElement(_document.Head, {
        __source: {
          fileName: _jsxFileName,
          lineNumber: 13
        }
      }, _react2.default.createElement('title', {
        __source: {
          fileName: _jsxFileName,
          lineNumber: 14
        }
      }, 'Open5GS'), _react2.default.createElement('meta', { charSet: 'utf-8', __source: {
          fileName: _jsxFileName,
          lineNumber: 16
        }
      }), _react2.default.createElement('meta', { httpEquiv: 'X-UA-Compatible', content: 'IE=edge,chrome=1', __source: {
          fileName: _jsxFileName,
          lineNumber: 17
        }
      }), _react2.default.createElement('meta', { name: 'viewport', content: 'width=device-width, initial-scale=1.0, user-scalable=no', __source: {
          fileName: _jsxFileName,
          lineNumber: 18
        }
      }), _react2.default.createElement('meta', { name: 'author', content: 'Open5GS', __source: {
          fileName: _jsxFileName,
          lineNumber: 20
        }
      }), _react2.default.createElement('meta', { name: 'description', content: description, __source: {
          fileName: _jsxFileName,
          lineNumber: 21
        }
      }), _react2.default.createElement('link', { rel: 'icon', href: '/static/favicon.ico', __source: {
          fileName: _jsxFileName,
          lineNumber: 23
        }
      }), _react2.default.createElement('link', { rel: 'stylesheet', type: 'text/css', href: '/static/css/bootstrap.min.css', __source: {
          fileName: _jsxFileName,
          lineNumber: 24
        }
      }), _react2.default.createElement('link', { rel: 'stylesheet', type: 'text/css', href: '/static/css/nprogress.css', __source: {
          fileName: _jsxFileName,
          lineNumber: 25
        }
      }), _react2.default.createElement('link', { rel: 'stylesheet', type: 'text/css', href: '/static/css/index.css', __source: {
          fileName: _jsxFileName,
          lineNumber: 26
        }
      }), styleTags), _react2.default.createElement('body', {
        __source: {
          fileName: _jsxFileName,
          lineNumber: 29
        }
      }, _react2.default.createElement('div', { className: 'root', __source: {
          fileName: _jsxFileName,
          lineNumber: 30
        }
      }, main), _react2.default.createElement(_document.NextScript, {
        __source: {
          fileName: _jsxFileName,
          lineNumber: 33
        }
      })));
    }
  }]);

  return MyDocument;
}(_document2.default);

exports.default = MyDocument;
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInBhZ2VzL19kb2N1bWVudC5qcyJdLCJuYW1lcyI6WyJEb2N1bWVudCIsIkhlYWQiLCJNYWluIiwiTmV4dFNjcmlwdCIsIlNlcnZlclN0eWxlU2hlZXQiLCJkZXNjcmlwdGlvbiIsIk15RG9jdW1lbnQiLCJzaGVldCIsIm1haW4iLCJjb2xsZWN0U3R5bGVzIiwic3R5bGVUYWdzIiwiZ2V0U3R5bGVFbGVtZW50Il0sIm1hcHBpbmdzIjoiOzs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7Ozs7QUFBQSxBQUFPLEFBQVksQUFBTSxBQUFNOzs7O0FBQy9CLEFBQVM7Ozs7Ozs7QUFFVCxJQUFNLGNBQU4sQUFBb0I7O0ksQUFFQzs7Ozs7Ozs7Ozs7NkJBQ1QsQUFDUjtVQUFNLFFBQU4sQUFBYyxBQUFJLEFBQ2xCO1VBQU0sYUFBTyxBQUFNLDhCQUFjLEFBQUM7O29CQUFEO3NCQUFqQyxBQUFhLEFBQW9CLEFBQ2pDO0FBRGlDO0FBQUEsT0FBQSxDQUFwQjtVQUNQLFlBQVksTUFBbEIsQUFBa0IsQUFBTSxBQUN4Qjs2QkFDRSxjQUFBOztvQkFBQTtzQkFBQSxBQUNFO0FBREY7QUFBQSxPQUFBLGtCQUNFLEFBQUM7O29CQUFEO3NCQUFBLEFBQ0U7QUFERjtBQUFBLHlCQUNFLGNBQUE7O29CQUFBO3NCQUFBO0FBQUE7QUFBQSxTQURGLEFBQ0UsQUFFQSxvREFBTSxTQUFOLEFBQWM7b0JBQWQ7c0JBSEYsQUFHRSxBQUNBO0FBREE7a0RBQ00sV0FBTixBQUFnQixtQkFBa0IsU0FBbEMsQUFBMEM7b0JBQTFDO3NCQUpGLEFBSUUsQUFDQTtBQURBO2tEQUNNLE1BQU4sQUFBVyxZQUFXLFNBQXRCLEFBQThCO29CQUE5QjtzQkFMRixBQUtFLEFBRUE7QUFGQTtrREFFTSxNQUFOLEFBQVcsVUFBUyxTQUFwQixBQUE0QjtvQkFBNUI7c0JBUEYsQUFPRSxBQUNBO0FBREE7a0RBQ00sTUFBTixBQUFXLGVBQWMsU0FBekIsQUFBa0M7b0JBQWxDO3NCQVJGLEFBUUUsQUFFQTtBQUZBO2tEQUVNLEtBQU4sQUFBVSxRQUFPLE1BQWpCLEFBQXNCO29CQUF0QjtzQkFWRixBQVVFLEFBQ0E7QUFEQTtrREFDTSxLQUFOLEFBQVUsY0FBYSxNQUF2QixBQUE0QixZQUFXLE1BQXZDLEFBQTRDO29CQUE1QztzQkFYRixBQVdFLEFBQ0E7QUFEQTtrREFDTSxLQUFOLEFBQVUsY0FBYSxNQUF2QixBQUE0QixZQUFXLE1BQXZDLEFBQTRDO29CQUE1QztzQkFaRixBQVlFLEFBQ0E7QUFEQTtrREFDTSxLQUFOLEFBQVUsY0FBYSxNQUF2QixBQUE0QixZQUFXLE1BQXZDLEFBQTRDO29CQUE1QztzQkFiRixBQWFFLEFBQ0M7QUFERDtVQWRKLEFBQ0UsQUFnQkEsNEJBQUEsY0FBQTs7b0JBQUE7c0JBQUEsQUFDRTtBQURGO0FBQUEseUJBQ0UsY0FBQSxTQUFLLFdBQUwsQUFBZTtvQkFBZjtzQkFBQSxBQUNHO0FBREg7U0FERixBQUNFLEFBR0EsdUJBQUEsQUFBQzs7b0JBQUQ7c0JBdEJOLEFBQ0UsQUFpQkUsQUFJRSxBQUlQO0FBSk87QUFBQTs7Ozs7QSxBQTNCOEI7O2tCLEFBQW5CIiwiZmlsZSI6Il9kb2N1bWVudC5qcz9lbnRyeSIsInNvdXJjZVJvb3QiOiIvaG9tZS81Z1Rlc3Qvb3BlbjVncy12Mi4yLjYvd2VidWkifQ==